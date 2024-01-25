// Redo Listing 7.15 without using the array class. Do two versions:
// a. Use an ordinary array of const char * for the strings representing the
// season names, and use an ordinary array of double for the expenses.
// b. Use an ordinary array of const char * for the strings representing the
// season names, and use a structure whose sole member is an ordinary array of
// double for the expenses. (This design is similar to the basic design of the
// array class.)

// =============================================================================
// Version a
// =============================================================================
// #include <iostream>
// #include <string>

// const int Seasons = 4;

// const char* Snames[] =
// {
    // "Spring",
    // "Summer",
    // "Fall",
    // "Winter"
// };

// void fill(double* expenses);
// void show(const double* expenses);

// int main()
// {
    // double expenses[Seasons] = {};
    
    // fill(expenses);
    // show(expenses);
    
    // return 0;
// }

// void fill(double* expenses)
// {
    // for (int i = 0; i < Seasons; i++)
    // {
        // std::cout << "Enter " << Snames[i] << " expenses: ";
        // std::cin >> expenses[i];
    // }
// }

// void show(const double* expenses)
// {
    // double total = 0.0;
    // std::cout << std::endl << "EXPENSES" << std::endl;
    
    // for (int i = 0; i < Seasons; i++)
    // {
        // std::cout << Snames[i] << ": $" << expenses[i] << std::endl;
        // total += expenses[i];
    // }
    
    // std::cout << "Total Expenses: $" << total << std::endl;
// }

// =============================================================================
// Version b
// =============================================================================
#include <iostream>
#include <string>

const int Seasons = 4;

const char* Snames[] =
{
    "Spring",
    "Summer",
    "Fall",
    "Winter"
};

struct budget
{
    double expenses[Seasons];
};

void fill(budget* b);
void show(budget* b);

int main()
{
    budget b = {};
    
    fill(&b);
    show(&b);
    
    return 0;
}

void fill(budget* b)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> b->expenses[i];
    }
}

void show(budget* b)
{
    double total = 0.0;
    std::cout << std::endl << "EXPENSES" << std::endl;
    
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << b->expenses[i] << std::endl;
        total += b->expenses[i];
    }
    
    std::cout << "Total expenses: $" << total << std::endl;
}