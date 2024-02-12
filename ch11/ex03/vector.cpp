#include "vector.h"

const double RAD_TO_DEG = 45.0 / std::atan(1.0);

// Constructors and destrcutors.

Vector::Vector()
{
    m_x = 0.0;
    m_y = 0.0;
    m_mode = RECTANGULAR;
}

Vector::Vector(double val1, double val2, Mode mode)
{
    m_mode = mode;
    
    switch(mode)
    {
        case RECTANGULAR:
            m_x = val1;
            m_y = val2;
            break;
        case POLAR:
            SetX(val1, val2 / RAD_TO_DEG);
            SetY(val1, val2 / RAD_TO_DEG);
            break;
        default:
            std::cout << "Incorrect mode -- vector set to default" << std::endl;
            m_x = 0.0;
            m_y = 0.0;
            m_mode = RECTANGULAR;
            break;
    }
}

Vector::~Vector() { }

// Public methods.

void Vector::Reset(double val1, double val2, Mode mode)
{
    m_mode = mode;
    
    switch(mode)
    {
        case RECTANGULAR:
            m_x = val1;
            m_y = val2;
            break;
        case POLAR:
            SetX(val1, val2 / RAD_TO_DEG);
            SetY(val1, val2 / RAD_TO_DEG);
            break;
        default:
            std::cout << "Incorrect mode -- vector set to default" << std::endl;
            m_x = 0.0;
            m_y = 0.0;
            m_mode = RECTANGULAR;
            break;
    }
}

void Vector::SetPolarMode()
{
    m_mode = POLAR;
}

void Vector::SetRectangularMode()
{
    m_mode = RECTANGULAR;
}

// Operator overloading.

Vector Vector::operator+(const Vector & vector) const
{
    return Vector(m_x + vector.m_x, m_y + vector.m_y);
}

Vector Vector::operator-(const Vector & vector) const
{
    return Vector(m_x - vector.m_x, m_y - vector.m_y);
}

Vector Vector::operator-() const
{
    return Vector(-m_x, -m_y);
}

Vector Vector::operator*(double value) const
{
    return Vector(m_x * value, m_y * value);
}

// Friend methods.

Vector operator*(double value, const Vector & vector)
{
    return vector * value;
}

std::ostream & operator<<(std::ostream & os, const Vector & vector)
{
    switch (vector.m_mode)
    {
        case Vector::RECTANGULAR:
            os << "(x = " << vector.m_x << ", y = " << vector.m_y << ")";
            break;
        case Vector::POLAR:
            os << "(magnitude = " << vector.GetMagnitude();
            os << ", angle = " << vector.GetAngle() * RAD_TO_DEG << ")";
            break;
        default:
            os << "Vector is in default mode";
            break;
    }
    
    return os;
}   