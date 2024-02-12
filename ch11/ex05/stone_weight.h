#ifndef STONE_WEIGHT_H_
#define STONE_WEIGHT_H_

#include <iostream>

class StoneWeight
{
public:
    enum Mode { STN, IPD, FPD };
private:
    Mode m_mode;
    int m_stones;
    double m_pounds;
    double m_pounds_left;
public:
    StoneWeight();
    StoneWeight(double pounds, Mode mode = STN);
    StoneWeight(int stones, double pounds, Mode mode = STN);
    ~StoneWeight() { }

    StoneWeight AsSTN() { m_mode = STN; return *this; }
    StoneWeight AsIPD() { m_mode = IPD; return *this; }
    StoneWeight AsFPD() { m_mode = FPD; return *this; }

    StoneWeight operator+(const StoneWeight & other) const;
    StoneWeight operator-(const StoneWeight & other) const;
    StoneWeight operator*(const StoneWeight & other) const;

    friend std::ostream & operator<<(std::ostream & os, const StoneWeight & sw);
};

#endif