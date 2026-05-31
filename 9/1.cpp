#include <iostream>
#include <cmath>
#include <cstring>

class Fraction
{
private:
    int count_digits(int n)
    {
        if (n == 0)
            return 1;
        return static_cast<int>(log10(abs(n))) + 1;
    }

public:
    bool negative = 0;
    int whole = 0;
    int num = 0;
    int denom = 0;

    Fraction() {}

    Fraction(int w, int n, int d) : negative((n xor d xor w) < 0), whole(w), num(n >= 0 ? n : -n), denom(d >= 0 ? d : -d) {}

    char *to_charptr()
    {
        // For '\0'
        int buffer_size = 1;

        // For '-'
        if (negative && (whole > 0 || num > 0))
        {
            ++buffer_size;
        }

        if (whole != 0)
        {
            buffer_size += count_digits(whole);
        }

        if (num != 0)
        {
            buffer_size += count_digits(num);
            buffer_size += count_digits(denom);
            ++buffer_size;
            if (whole != 0)
            {
                ++buffer_size;
            }
        }

        // For 0
        if (whole == 0 && num == 0)
        {
            ++buffer_size;
        }

        char *buf = new char[buffer_size];
        char *ptr = buf;

        if (negative && (whole > 0 || num > 0))
        {
            *ptr = '-';
            ++ptr;
        }

        if (whole != 0)
        {
            ptr += sprintf(ptr, "%d", abs(whole));
        }

        if (num != 0)
        {
            if (whole != 0)
            {
                *ptr = ' ';
                ++ptr;
            }
            ptr += sprintf(ptr, "%d/%d", abs(num), abs(denom));
        }
        else if (whole == 0)
        {
            sprintf(ptr, "0");
        }
        else
        {
            *ptr = 0;
        }

        return buf;
    }
};

double sum(double x, double y)
{
    return x + y;
}

double sum(double x, Fraction *y)
{
    return x + (y->negative ? -1 : 1) * (y->whole + static_cast<double>(y->num) / y->denom);
}

Fraction *sum(Fraction *x, Fraction *y)
{
    Fraction *f = new Fraction();

    int x_num = x->whole * x->denom + x->num;
    int y_num = y->whole * y->denom + y->num;

    if (x->negative)
        x_num = -x_num;
    if (y->negative)
        y_num = -y_num;

    f->num = x_num * y->denom + y_num * x->denom;

    f->negative = (f->num xor f->denom) < 0;
    f->denom = abs(x->denom * y->denom);
    f->whole = abs(f->num / f->denom);
    f->num = abs(f->num % f->denom);

    int a = f->num;
    int b = f->denom;

    int max_nod = 1;
    int limit = std::min(f->num, f->denom);

    for (int i = 2; i <= limit; ++i)
    {
        if (f->num % i == 0 && f->denom % i == 0)
        {
            max_nod = i;
        }
    }

    if (max_nod > 1)
    {
        f->num /= max_nod;
        f->denom /= max_nod;
    }

    return f;
}

int main()
{
    std::cout << "sum(3.5, 2.7) = " << sum(3.5, 2.7) << std::endl;

    Fraction f4(1, 1, 2);
    std::cout << "sum(2.3, &f4) = " << sum(2.3, &f4) << std::endl;

    Fraction f5(1, 1, 3);
    Fraction f6(2, 15, 24);
    Fraction *result = sum(&f5, &f6);
    char *result_str = result->to_charptr();

    std::cout << "sum(1 1/3, 2 15/24) = " << result_str << std::endl;

    delete[] result_str;
    delete result;

    return 0;
}