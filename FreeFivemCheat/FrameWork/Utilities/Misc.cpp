#include "Misc.hpp"

#include <FrameWork/FrameWork.hpp>
#include <algorithm>
#include <winhttp.h>
#include <sstream>
#include <tchar.h>

namespace FrameWork
{
	int Misc::RandomInt(int Lower, int Max)
	{
		return (rand() % (Max - Lower + 1)) + Lower;
	}

	std::wstring Misc::RandomString(size_t Length)
	{
		auto Randchar = []() -> char
			{
				const char* Charset = XorStr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
				const size_t MaxIndex = (sizeof(Charset) - 1);
				return Charset[rand() % MaxIndex];
			};

		std::wstring Str(Length, 0);
		std::generate_n(Str.begin(), Length, Randchar);
		return Str;
	}

	std::string Misc::Wstring2String(std::wstring Input)
	{
		return std::string(Input.begin(), Input.end());
	}

	std::wstring Misc::String2WString(std::string Input)
	{
		return std::wstring(Input.begin(), Input.end());
	}

	void Misc::InitializeConsole()
	{
		SafeCall(AllocConsole)();
		freopen(XorStr("CONIN$"), XorStr("r"), stdin);
		freopen(XorStr("CONOUT$"), XorStr("w"), stdout);
		SafeCall(SetConsoleTitleA)(XorStr("Debug Console"));
	}

	void Misc::ShutDownConsole()
	{
		SafeCall(FreeConsole)();
	}

	std::string Misc::DownloadServerInfo(std::wstring IP, int PORT)
	{
		HINTERNET hSession = WinHttpOpen(XorStr(L"A WinHTTP FiveM Request Program/1.0"), WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

		if (hSession)
		{
			HINTERNET hConnect = WinHttpConnect(hSession, IP.c_str(), PORT, 0);

			if (hConnect)
			{
				HINTERNET hRequest = WinHttpOpenRequest(hConnect, XorStr(L"GET"), XorStr(L"/players.json"), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

				if (hRequest)
				{
					if (WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0))
					{
						if (WinHttpReceiveResponse(hRequest, NULL)) 
						{
							DWORD dwSize = 0;
							DWORD dwDownloaded = 0;
							LPSTR pszOutBuffer;
							BOOL  bResults = FALSE;
							std::string Response;

							do 
							{
								dwSize = 0;
								if (WinHttpQueryDataAvailable(hRequest, &dwSize))
								{
									pszOutBuffer = new char[dwSize + 1];
									if (!pszOutBuffer)
									{
										dwSize = 0;
									}
									else
									{
										ZeroMemory(pszOutBuffer, dwSize + 1);

										if (WinHttpReadData(hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded))
											Response.append(pszOutBuffer, dwDownloaded);
									}

									delete[] pszOutBuffer;
								}

							} while (dwSize > 0);

							return Response;
						}
					}

					WinHttpCloseHandle(hRequest);
				}

				WinHttpCloseHandle(hConnect);
			}

			WinHttpCloseHandle(hSession);
		}

		return XorStr("");
	}
}