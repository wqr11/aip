#include <iostream>

class CNumber
{
public:
    double real;
    double imaginary;

    CNumber() : real(0), imaginary(0) {}

    CNumber(double r, double i) : real(r), imaginary(i) {}

    // =============== + ==============
    CNumber operator+(CNumber &other)
    {
        return CNumber(this->real + other.real, this->imaginary + other.imaginary);
    }

    template <typename T>
    CNumber operator+(T other)
    {
        return CNumber(this->real + other, this->imaginary);
    }

    // =============== - ==============

    CNumber operator-(CNumber &other)
    {
        return CNumber(this->real - other.real, this->imaginary - other.imaginary);
    }

    template <typename T>
    CNumber operator-(T other)
    {
        return CNumber(this->real - other, this->imaginary);
    }
};

class Mat
{

private:
    CNumber *d = nullptr;

public:
    int size_i = 0;
    int size_j = 0;
    int size_k = 0;

    Mat(int __size_i, int __size_j, int __size_k) : size_i(__size_i), size_j(__size_j), size_k(__size_k)
    {
        this->d = new CNumber[size_i * size_j * size_k]();
    }

    CNumber &at(int __i, int __j, int __k)
    {
        return this->d[(__i * size_j * size_k) + (__j * size_k) + __k];
    }

    Mat operator+(Mat &other)
    {
        if (size_i != other.size_i || size_j != other.size_j || size_k != other.size_k)
        {
            throw std::runtime_error("Matrices dimensions do not match!");
        }

        Mat r(size_i, size_j, size_k);

        int total = size_i * size_j * size_k;

        for (int i = total - 1; i >= 0; --i)
        {
            r.d[i].real = this->d[i].real + other.d[i].real;
            r.d[i].imaginary = this->d[i].imaginary + other.d[i].imaginary;
        }

        return r;
    }

    Mat operator-(Mat &other)
    {
        if (size_i != other.size_i || size_j != other.size_j || size_k != other.size_k)
        {
            throw std::runtime_error("Matrices dimensions do not match!");
        }

        Mat r(size_i, size_j, size_k);

        int total = size_i * size_j * size_k;

        for (int i = total - 1; i >= 0; --i)
        {
            r.d[i].real = this->d[i].real - other.d[i].real;
            r.d[i].imaginary = this->d[i].imaginary - other.d[i].imaginary;
        }

        return r;
    }

    void print()
    {
        for (int i = 0; i < size_i; ++i)
        {
            std::cout << "Слой x=" << i << ":" << std::endl;
            for (int j = 0; j < size_j; ++j)
            {
                std::cout << "  y=" << j << ": ";
                for (int k = 0; k < size_k; ++k)
                {
                    CNumber val = at(i, j, k);
                    std::cout << "(" << val.real;
                    if (val.imaginary < 0)
                        std::cout << " - " << -val.imaginary;
                    else
                        std::cout << " + " << val.imaginary;
                    std::cout << "i) ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    ~Mat()
    {
        delete[] d;
    }
};

int main()
{
    Mat m1(2, 2, 2);
    Mat m2(2, 2, 2);

    m1.at(0, 0, 0) = CNumber(1, -2);
    m1.at(0, 0, 1) = CNumber(2, 3);
    m1.at(0, 1, 0) = CNumber(3, 4);
    m1.at(0, 1, 1) = CNumber(4, 0);
    m1.at(1, 0, 0) = CNumber(5, 2);
    m1.at(1, 0, 1) = CNumber(6, -1);
    m1.at(1, 1, 0) = CNumber(7, 8);
    m1.at(1, 1, 1) = CNumber(8, 3);

    m2.at(0, 0, 0) = CNumber(8, 11);
    m2.at(0, 0, 1) = CNumber(7, -4);
    m2.at(0, 1, 0) = CNumber(6, 5);
    m2.at(0, 1, 1) = CNumber(5, 6);
    m2.at(1, 0, 0) = CNumber(4, -8);
    m2.at(1, 0, 1) = CNumber(3, 0);
    m2.at(1, 1, 0) = CNumber(2, 2);
    m2.at(1, 1, 1) = CNumber(1, 0);

    Mat m3 = m1 + m2;

    m3.print();

    Mat m4 = m1 - m2;

    m4.print();

    return 0;
}