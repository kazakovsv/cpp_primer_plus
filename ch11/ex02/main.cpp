#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "vector.h"

int main()
{
    srand(time(0));

    double direction = 0.0;
    Vector step;
    Vector result;
    unsigned long step_count = 0;
    double target = 0.0;
    double step_length = 0.0;

    std::cout << "Enter target distance (q to quit): ";

    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";

        if (!(std::cin >> step_length))
        {
            break;
        }
        
        std::cout << "Target Distance: " << target << ", Step Size: " << step_length
                  << std::endl;

        while (result.GetMagnitude() < target)
        {
            direction = rand() % 360;
            step.Reset(step_length, direction, Vector::POLAR);
            result = result + step;
            ++step_count;
        }

        std::cout << "After " << step_count << " steps, the subject "
                     "has the following location:" << std::endl;
        std::cout << result << std::endl;
        result.SetPolarMode();
        std::cout << " or" << std::endl << result << std::endl;
        std::cout << "Average outward distance per step = "
             << result.GetMagnitude() / step_length << std::endl;

        step_count = 0;
        result.Reset(0.0, 0.0);
        std::cout << "Enter target distance (q to quit): ";
    }
    
    std::cout << "Bye!" << std::endl;
    std::cin.clear();
    
    while (std::cin.get() != '\n')
    {
        continue;
    }

    return 0;
}