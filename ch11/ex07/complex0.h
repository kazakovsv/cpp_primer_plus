#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex
{
private:
    double m_real;
    double m_imaginary;
public:
    complex() { m_real = 0.0; m_imaginary = 0.0; }
    complex(double real, double imaginary = 0.0);
    ~complex() {}
    
    complex operator+(const complex & other) const;
    complex operator-(const complex & other) const;
    complex operator*(const complex & other) const;
    complex operator*(double  value) const;
    complex operator~() const;
    
    friend complex operator*(double value, const complex & current);
    friend std::ostream & operator<<(std::ostream & os, const complex & current);
    friend std::istream & operator>>(std::istream & is, complex & current);
};

#endif