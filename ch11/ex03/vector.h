#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <cmath>

class Vector
{
public:
    enum Mode { RECTANGULAR, POLAR };

private:
    double m_x;
    double m_y;
    Mode m_mode;
    
    void SetX(double magnitude, double angle) { m_x = magnitude * std::cos(angle); }
    void SetY(double magnitude, double angle) { m_y = magnitude * std::sin(angle); }

public:
    Vector();
    Vector(double, double, Mode mode = RECTANGULAR);
    ~Vector();
    
    double GetX() const { return m_x; }
    double GetY() const { return m_y; }
    double GetAngle() const { return std::atan2(m_y, m_x); }
    double GetMagnitude() const { return std::sqrt(m_x * m_x + m_y * m_y); }
    void Reset(double, double, Mode mode = RECTANGULAR);
    void SetPolarMode();
    void SetRectangularMode();
    
    Vector operator+(const Vector & vector) const;
    Vector operator-(const Vector & vector) const;
    Vector operator-() const;
    Vector operator*(double value) const;
    
    friend Vector operator*(double value, const Vector & vector);
    friend std::ostream & operator<<(std::ostream & os, const Vector & vector);
};

#endif