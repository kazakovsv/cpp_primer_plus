#include <iostream>

#include "stone_weight.h"

int main()
{
    StoneWeight sw1 = 125.25;
    StoneWeight sw2(311.79);
    StoneWeight sw3(21, 8.36);
    
    std::cout << "SW #1: " << sw1 << std::endl;
    std::cout << "SW #2: " << sw2 << std::endl;
    std::cout << "SW #3: " << sw3 << std::endl;
    std::cout << std::endl;
    std::cout << "SW #1 as stones: " << sw1.AsSTN() << std::endl;
    std::cout << "SW #1 as integer pounds: " << sw1.AsIPD() << std::endl;
    std::cout << "SW #1 as decimal pounds: " << sw1.AsFPD() << std::endl;
    std::cout << std::endl;
    std::cout << "SW #2 + SW #3: " << sw2 + sw3 << std::endl;
    std::cout << "SW #2 - SW #3: " << sw2 - sw3 << std::endl;
    std::cout << "SW #2 * SW #3: " << sw3 * sw3 << std::endl;

    return 0;
}