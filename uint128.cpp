typedef unsigned long long uint64;

class uint128
{
private:
    uint64 high;
    uint64 low;

public:
    uint128() : high(0), low(0) {}
    uint128(uint64 value) : high(0), low(value) {}
    uint128(int value) : high(0), low(value) {}

    uint128 operator+(const uint128 &other)
    {
        uint128 result;
        result.low = this->low + other.low;
        result.high = this->high + other.high + (result.low < low ? 1 : 0);
        return result;
    }

    uint128 operator+(const int other)
    {
        uint128 result;
        result.low = this->low + other;
        result.high = this->high + (result.low < this->low ? 1 : 0);
        return result;
    }

    uint128 operator*(const int m) const
    {
        if (m == 0)
            return uint128();
        if (m == 1)
            return *this;

        uint128 result = *this;
        uint128 multiplier = *this;

        for (int i = 1; i < m; i++)
        {
            result = result + multiplier;
        }

        return result;
    }

    uint128 &operator=(const uint128 &other)
    {
        if (this == &other)
        {
            return *this;
        }

        this->high = other.high;
        this->low = other.low;

        return *this;
    }

    uint128 &operator=(const int other)
    {
        this->high = 0;
        this->low = other;
        return *this;
    }

    bool operator==(const int other)
    {
        return this->low == other && this->high == 0;
    }

    bool operator!=(const int other)
    {
        return !(*this == other);
    }
};