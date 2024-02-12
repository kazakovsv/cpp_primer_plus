#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

class Vector
{
public:
    enum Mode { RECTANGULAR, POLAR };

private:
    double m_x;
    double m_y;
    double m_angle;
    double m_magnitude;
    Mode m_mode;
    
    void SetX();
    void SetY();
    void SetAngle();
    void SetMagnitude();

public:
    Vector();
    Vector(double, double, Mode mode = RECTANGULAR);
    ~Vector();
    
    double GetX() const { return m_x; }
    double GetY() const { return m_y; }
    double GetAngle() const { return m_angle; }
    double GetMagnitude() const { return m_magnitude; }
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