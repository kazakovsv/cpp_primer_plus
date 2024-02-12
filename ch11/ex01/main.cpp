#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "vector.h"

int main()
{
    const char* output_file_path = "output.txt";
    
    srand(time(0));

    double direction = 0.0;
    Vector step;
    Vector result;
    unsigned long step_count = 0;
    double target = 0.0;
    double step_length = 0.0;
    std::ofstream fout;

    std::cout << "Enter target distance (q to quit): ";

    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";

        if (!(std::cin >> step_length))
        {
            break;
        }
        
        fout.open(output_file_path);
        
        if (!fout)
        {
            std::cerr << "ERROR: File: \"" << output_file_path
                      << "\" could not be opened" << std::endl;
            exit(1);
        }
        
        fout << "Target Distance: " << target << ", Step Size: " << step_length
             << std::endl;
        fout << step_count << ": " << result << std::endl;

        while (result.GetMagnitude() < target)
        {
            direction = rand() % 360;
            step.Reset(step_length, direction, Vector::POLAR);
            result = result + step;
            ++step_count;
            fout << step_count << ": " << result << std::endl;
        }

        fout << "After " << step_count << " steps, the subject "
                "has the following location:" << std::endl;
        fout << result << std::endl;
        result.SetPolarMode();
        fout << " or" << std::endl << result << std::endl;
        fout << "Average outward distance per step = "
             << result.GetMagnitude() / step_length << std::endl;
        fout.close();
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