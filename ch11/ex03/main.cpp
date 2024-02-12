#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

#include "vector.h"

int main()
{
    srand(time(0));

    double direction = 0.0;
    Vector step;
    Vector result;
    unsigned long step_count = 0;
    unsigned long step_count_min = ULONG_MAX;
    unsigned long step_count_max = 0;
    unsigned long step_count_sum = 0;
    unsigned long attempts = 0;
    double target = 0.0;
    double step_length = 0.0;

    std::cout << "Enter target distance (q to quit): ";

    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";

        if (!(std::cin >> step_length))
        {
            std::cerr << "ERROR: Incorrect value" << std::endl;
            break;
        }
        
        std::cout << "Enter the number of attempts: ";
        
        if (!(std::cin >> attempts))
        {
            std::cerr << "ERROR: Incorrect value" << std::endl;
            break;
        }
        
        for (int i = 0; i < attempts; i++)
        {
            while (result.GetMagnitude() < target)
            {
                direction = rand() % 360;
                step.Reset(step_length, direction, Vector::POLAR);
                result = result + step;
                ++step_count;
            }
            
            step_count_sum += step_count;
            
            if (step_count < step_count_min)
            {
                step_count_min = step_count;
            }
            
            if (step_count > step_count_max)
            {
                step_count_max = step_count;
            }
            
            step_count = 0;
            result.Reset(0.0, 0.0);
        }

        std::cout << "Number of Steps" << std::endl;
        std::cout << "Min: " << step_count_min << std::endl;
        std::cout << "Max: " << step_count_max << std::endl;
        std::cout << "Average: " << step_count_sum / attempts << std::endl;

        step_count = 0;
        step_count_sum = 0;
        step_count_min = ULONG_MAX;
        step_count_max = 0;
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