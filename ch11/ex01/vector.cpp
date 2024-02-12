#include <cmath>
#include "vector.h"

const double RAD_TO_DEG = 45.0 / std::atan(1.0);

// Constructors and destrcutors.

Vector::Vector()
{
    m_x = 0.0;
    m_y = 0.0;
    m_angle = 0.0;
    m_magnitude = 0.0;
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
            SetAngle();
            SetMagnitude();
            break;
        case POLAR:
            m_angle = val2 / RAD_TO_DEG;
            m_magnitude = val1;
            SetX();
            SetY();
            break;
        default:
            std::cout << "Incorrect mode -- vector set to default" << std::endl;
            m_x = 0.0;
            m_y = 0.0;
            m_angle = 0.0;
            m_magnitude = 0.0;
            m_mode = RECTANGULAR;
            break;
    }
}

Vector::~Vector() { }

// Private methods.

void Vector::SetX()
{
    m_x = m_magnitude * std::cos(m_angle);
}

void Vector::SetY()
{
    m_y = m_magnitude * std::sin(m_angle);
}

void Vector::SetAngle()
{
    if (m_x == 0.0 && m_y == 0.0)
    {
        m_angle = 0.0;
    }
    else
    {
        m_angle = std::atan2(m_y, m_x);
    }
}

void Vector::SetMagnitude()
{
    m_magnitude = std::sqrt(m_x * m_x + m_y * m_y);
}

// Public methods.

void Vector::Reset(double val1, double val2, Mode mode)
{
    m_mode = mode;
    
    switch(mode)
    {
        case RECTANGULAR:
            m_x = val1;
            m_y = val2;
            SetAngle();
            SetMagnitude();
            break;
        case POLAR:
            m_angle = val2 / RAD_TO_DEG;
            m_magnitude = val1;
            SetX();
            SetY();
            break;
        default:
            std::cout << "Incorrect mode -- vector set to default" << std::endl;
            m_x = 0.0;
            m_y = 0.0;
            m_angle = 0.0;
            m_magnitude = 0.0;
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
            os << "(magnitude = " << vector.m_magnitude;
            os << ", angle = " << vector.m_angle * RAD_TO_DEG << ")";
            break;
        default:
            os << "Vector is in default mode";
            break;
    }
    
    return os;
}