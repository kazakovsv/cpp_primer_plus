#include <iostream>
#include "time.h"

int main()
{
    Time t1(3, 15);
    Time t2(9, 45);
    
    std::cout << "T1: " << t1 << std::endl;
    std::cout << "T2: " << t2 << std::endl;
    std::cout << "T1 + T2: " << t1 + t2 << std::endl;
    std::cout << "T2 + T1: " << t2 + t1 << std::endl;
    std::cout << "T1 - T2: " << t1 - t2 << std::endl;
    std::cout << "T2 - T1: " << t2 - t1 << std::endl;
    std::cout << "T1 * 2: " << t1 * 2 << std::endl;
    std::cout << "2 * T2: " << 2 * t2 << std::endl;
    
    return 0;
}