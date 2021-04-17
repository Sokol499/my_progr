#include <iostream>
using namespace std;

class Coordinate
{
private:
    int x_;
    int y_;
    int z_;
public:

    Coordinate(int x, int y, int z) : x_(x), y_(y), z_(z) {}

    ~Coordinate(){}

    void Print() const
    {
        cout << "Coordinate(x, y, z) = (" << x_ << ", " << y_ << ", " << z_ << ")" << endl;
    }

    bool operator==(const Coordinate& other) const
    {
        return x_ == other.x_ && y_ == other.y_ && z_ == other.z_;
    }

    bool operator<=(const Coordinate& other) const
    {
        int len1 = x_ * x_ + y_ * y_ + z_ * z_;
        int len2 = other.x_ * other.x_ + other.y_ * other.y_ + other.z_ * other.z_;
        return len1 <= len2;
    }

    bool operator>=(const Coordinate& other) const
    {
        int len1 = x_ * x_ + y_ * y_ + z_ * z_;
        int len2 = other.x_ * other.x_ + other.y_ * other.y_ + other.z_ * other.z_;
        return len1 >= len2;
    }

    bool operator>(const Coordinate& other) const
    {
        int len1 = x_ * x_ + y_ * y_ + z_ * z_;
        int len2 = other.x_ * other.x_ + other.y_ * other.y_ + other.z_ * other.z_;
        return len1 > len2;
    }

    bool operator<(const Coordinate& other) const
    {
        int len1 = x_ * x_ + y_ * y_ + z_ * z_;
        int len2 = other.x_ * other.x_ + other.y_ * other.y_ + other.z_ * other.z_;
        return len1 < len2;
    }

    Coordinate operator+=(const Coordinate& other)
    {
        x_ += other.x_;
        y_ += other.y_;
        z_ += other.z_;
        return *this;
    }
    
    Coordinate operator-=(const Coordinate& other)
    {
        x_ -= other.x_;
        y_ -= other.y_;
        z_ -= other.z_;
        return *this;
    }

    Coordinate operator*=(const Coordinate& other)
    {
        x_ *= other.x_;
        y_ *= other.y_;
        z_ *= other.z_;
        return *this;
    }

    Coordinate operator/=(const Coordinate& other)
    {
        x_ /= other.x_;
        y_ /= other.y_;
        z_ /= other.z_;
        return *this;
    }

    Coordinate operator%=(const Coordinate& other)
    {
        x_ %= other.x_;
        y_ %= other.y_;
        z_ %= other.z_;
        return *this;
    }
};


int main()
{
    return 0;
}