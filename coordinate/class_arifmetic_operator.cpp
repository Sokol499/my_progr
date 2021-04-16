#include <iostream>
using namespace std;

class Coordinate
{
private:
    int x;
    int y;
    int z;
public:

    Coordinate(int x_, int y_, int z) : x(x_), y(y_), z(z)
    {
    }

    ~Coordinate()
    {
    }

    void Print() const
    {
        cout << "Coordinate(x, y, z) = (" << x << ", " << y << ", " << z << ")" << endl;
    }

    bool operator==(const Coordinate& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator<=(const Coordinate& other) const
    {
        int len1 = x * x + y * y + z * z;
        int len2 = other.x * other.x + other.y * other.y + other.z * other.z;
        return len1 < len2;
    }

    bool operator>=(const Coordinate& other) const
    {
        int len1 = x * x + y * y + z * z;
        int len2 = other.x * other.x + other.y * other.y + other.z * other.z;
        return len1 > len2;
    }

    bool operator>(const Coordinate& other) const
    {
        int len1 = x * x + y * y + z * z;
        int len2 = other.x * other.x + other.y * other.y + other.z * other.z;
        return len1 > len2;
    }

    bool operator<(const Coordinate& other) const
    {
        int len1 = x * x + y * y + z * z;
        int len2 = other.x * other.x + other.y * other.y + other.z * other.z;
        return len1 < len2;
    }

    Coordinate operator+=(const Coordinate& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    
    Coordinate operator-=(const Coordinate& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Coordinate operator*=(const Coordinate& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Coordinate operator/=(const Coordinate& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Coordinate operator%=(const Coordinate& other)
    {
        x %= other.x;
        y %= other.y;
        z %= other.z;
        return *this;
    }
};


int main()
{
    return 0;
}