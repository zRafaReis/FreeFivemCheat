#pragma once

#include <cmath>

class Vector3D
{
public:
    // Members
    float x, y, z;

    Vector3D(void) { }
    Vector3D(float X, float Y, float Z) { x = X; y = Y; z = Z; }

    Vector3D operator + (const Vector3D& rhs) const { return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z); }

    float DistTo(const Vector3D& vOther) const
    {
        Vector3D delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.Length();
    }

    float Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    float LengthSqr(void) const
    {
        return (x * x + y * y + z * z);
    }

    float Length2D() const
    {
        return sqrt(x * x + y * y);
    }
};