#include <iostream>
#include "ex04_sales.h"

namespace SALES
{
    // copies the lesser of 4 or n items from the array ar
    // to the sales member of s and computes and stores the
    // average, maximum, and minimum values of the entered items;
    // remaining elements of sales, if any, set to 0
    void setSales(Sales & s, const double ar[], int n)
    {
        double min = ar[0];
        double max = ar[0];
        double sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (i >= QUARTERS)
            {
                s.sales[i] = 0.0;
            }
            else
            {
                s.sales[i] = ar[i];
                sum += ar[i];
                
                if (ar[i] < min)
                {
                    min = ar[i];
                }
                
                if (ar[i] > max)
                {
                    max = ar[i];
                }
            }
        }
        
        s.min = min;
        s.max = max;
        s.average = sum / QUARTERS;
    }
    
    // gathers sales for 4 quarters interactively, stores them
    // in the sales member of s and computes and stores the
    // average, maximum, and minimum values
    void setSales(Sales & s)
    {
        std::cout << "Enter sales for 4 quarters:" << std::endl;
        double temp[QUARTERS];
        
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << "Quarter #" << i + 1 << ": ";
            std::cin >> temp[i];
        }
        
        setSales(s, temp, QUARTERS);
    }
    
    // display all information in structure s
    void showSales(const Sales & s)
    {
        std::cout << std::endl << "Sales:" << std::endl;
        
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << "Quarter #" << i + 1 << ": " << s.sales[i] << std::endl;
        }
        
        std::cout << "Min: " << s.min << std::endl;
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Average: " << s.average << std::endl;
    }
}