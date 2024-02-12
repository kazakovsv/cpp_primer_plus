#include <iostream>

#include "stone_weight.h"

const int PD_PER_STN = 14;

StoneWeight::StoneWeight()
{
    m_mode = STN;
    m_stones = 0;
    m_pounds = 0.0;
    m_pounds_left = 0.0;
}

StoneWeight::StoneWeight(double pounds, Mode mode)
{
    m_mode = mode;
    m_stones = int (pounds) / PD_PER_STN;
    m_pounds = pounds;
    m_pounds_left = int (pounds) % PD_PER_STN + pounds - int (pounds);
}

StoneWeight::StoneWeight(int stones, double pounds, Mode mode)
{
    m_mode = mode;
    m_stones = stones;
    m_pounds = stones * PD_PER_STN + pounds;
    m_pounds_left = pounds;
}

StoneWeight StoneWeight::operator+(const StoneWeight & other) const
{
    return StoneWeight(m_pounds + other.m_pounds);
}

StoneWeight StoneWeight::operator-(const StoneWeight & other) const
{
    return StoneWeight(m_pounds - other.m_pounds);
}

StoneWeight StoneWeight::operator*(const StoneWeight & other) const
{
    return StoneWeight(m_pounds * other.m_pounds);
}

std::ostream & operator<<(std::ostream & os, const StoneWeight & sw)
{
    switch (sw.m_mode)
    {
        case StoneWeight::STN:
            os << sw.m_stones << " stones";
            break;
        case StoneWeight::IPD:
            os << int (sw.m_pounds) << " pounds";
            break;
        case StoneWeight::FPD:
            os << sw.m_pounds << " pounds";
            break;
        default:
            os << "ERROR: Invalid value";
            break;
    }
    
    return os;
}