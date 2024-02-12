#include <iostream>
#include <cstdlib>

#include "stone_weight.h"

int main()
{
    StoneWeight weights[6] = { 3.55, 11.26, 78.12 };
    double weight = 0.0;

    for (int i = 3; i < 6; i++)
    {
        std::cout << "Enter a decimal: ";
        std::cin >> weight;
        
        if (!std::cin)
        {
            std::cout << "ERROR: Incorrect input" << std::endl;
            exit(1);
        }
        
        weights[i] = weight;
    }
    
    StoneWeight min = weights[0];
    StoneWeight max = weights[0];
    StoneWeight pattern(11);
    int count = 0;
    
    for (int i = 0; i < 6; i++)
    {
        if (weights[i] < min)
        {
            min = weights[i];
        }
        
        if (weights[i] > max)
        {
            max = weights[i];
        }
        
        if (weights[i] >= pattern)
        {
            count++;
        }
    }
    
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Greater than or equal to 11: " << count << std::endl;

    return 0;
}