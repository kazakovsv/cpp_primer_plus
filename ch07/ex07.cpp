// Redo Listing 7.7, modifying the three array-handling functions to each use
// two pointer parameters to represent a range. The fill_array() function,
// instead of returning the actual number of items read, should return a
// pointer to the location after the last location filled; the other functions
// can use this pointer as the second argument to identify the end of the data.

#include <iostream>

const int Max = 5;

double* fill_array(double* start, const double* end);
void show_array(const double* start, const double* end);
void revalue(double r, double* start, const double* end);

int main()
{
    using namespace std;
    
    double properties[Max];
    double* end = fill_array(properties, properties + Max - 1);
    show_array(properties, end);
    
    if (end != nullptr)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        
        while (!(cin >> factor))
        {
            cin.clear();
            
            while (cin.get() != '\n')
            {
                continue;
            }
            
            cout << "Bad input; Please enter a number: ";
        }
        
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    
    cout << "Done." << endl;
    
    return 0;
}

double* fill_array(double* start, const double* end)
{
    double* current;
    double value = 0.0;
    int i = 0;
    
    for (current = start; current != end; current++)
    {
        std::cout << "Enter value #" << ++i << ": ";
        
        if (!(std::cin >> value))
        {
            std::cin.clear();
            
            while (std::cin.get() != '\n')
            {
                continue;
            }
            
            std::cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (value < 0)
        {
            break;
        }
        
        *current = value;
    }
    
    return current;
}

void show_array(const double* start, const double* end)
{
    int i = 0;
    
    for (const double* current = start; current != end; current++)
    {
        std::cout << "Property #" << ++i << ": $";
        std::cout << *current << std::endl;
    }
}

void revalue(double r, double* start, const double* end)
{
    for (double* current = start; current != end; current++)
    {
        *current *= r;
    }
}