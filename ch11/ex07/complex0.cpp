#include <iostream>
#include "complex0.h"

complex::complex(double real, double imaginary)
{
    m_real = real;
    m_imaginary = imaginary;
}

complex complex::operator+(const complex & other) const
{
    return complex(m_real + other.m_real, m_imaginary + other.m_imaginary);
}

complex complex::operator-(const complex & other) const
{
    return complex(m_real - other.m_real, m_imaginary - other.m_imaginary);
}

complex complex::operator*(const complex & other) const
{
    double real = m_real * other.m_real - m_imaginary * other.m_imaginary;
    double imaginary = m_real * other.m_imaginary + m_imaginary * other.m_real;
    
    return complex(real, imaginary);
}

complex complex::operator*(double  value) const
{
    return complex(m_real * value, m_imaginary * value);
}

complex complex::operator~() const
{
    return complex(m_real, -m_imaginary);
}

complex operator*(double value, const complex & current)
{
    return current * value;
}

std::ostream & operator<<(std::ostream & os, const complex & current)
{
    os << "(" << current.m_real << "," << current.m_imaginary << "i)";
    
    return os;
}

std::istream & operator>>(std::istream & is, complex & current)
{
    std::cout << "real: ";
    
    if (is >> current.m_real)
    {
        std::cout << "imaginary: ";
        is >> current.m_imaginary;
    }
    
    return is;
}