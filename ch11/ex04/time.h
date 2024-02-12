#ifndef TIME_H_
#define TIME_H_

#include <iostream>

class Time
{
private:
    int m_hours;
    int m_minutes;
public:
    Time();
    Time(int hours, int minutes = 0);
    friend Time operator+(const Time & left, const Time & right);
    friend Time operator-(const Time & left, const Time & right);
    friend Time operator*(const Time & time, double value);
    friend Time operator*(double value, const Time & time);
    friend std::ostream & operator<<(std::ostream & os, const Time & time);
};

#endif