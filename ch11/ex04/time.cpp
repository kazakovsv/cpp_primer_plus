#include "time.h"

const int MINUTES_PER_HOUR = 60;

Time::Time()
{
    m_hours = 0;
    m_minutes = 0;
}

Time::Time(int hours, int minutes)
{
    m_hours = hours;
    m_minutes = minutes;
}

Time operator+(const Time & left, const Time & right)
{
    int total_minutes = (left.m_hours + right.m_hours) * MINUTES_PER_HOUR + left.m_minutes + right.m_minutes;
    
    return Time(total_minutes / MINUTES_PER_HOUR, total_minutes % MINUTES_PER_HOUR);
}

Time operator-(const Time & left, const Time & right)
{
    int total_minutes = (left.m_hours * MINUTES_PER_HOUR + left.m_minutes) - (right.m_hours * MINUTES_PER_HOUR + right.m_minutes);

    return Time(total_minutes / MINUTES_PER_HOUR, total_minutes % MINUTES_PER_HOUR);
}

Time operator*(const Time & time, double value)
{
    int total_minutes = time.m_hours * MINUTES_PER_HOUR * value + time.m_minutes * value;
    
    return Time(total_minutes / MINUTES_PER_HOUR, total_minutes % MINUTES_PER_HOUR);
}

Time operator*(double value, const Time & time)
{
    return time * value;
}

std::ostream & operator<<(std::ostream & os, const Time & time)
{
    os << time.m_hours << ":" << time.m_minutes;
    
    return os;
}