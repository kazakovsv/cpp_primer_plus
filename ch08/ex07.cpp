// Modify Listing 8.14 so that it uses two template functions called SumArray()
// to return the sum of the array contents instead of displaying the contents.
// The program now should report the total number of things and the sum of all
// the debts.

#include <iostream>

template <typename T> T SumArray(T source[], int n);
template <typename T> T SumArray(T* source[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];
    
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }
    
    std::cout << "The amount of Mr. E's things: "
              << SumArray(things, 6) << std::endl;
    
    std::cout << "The amount of Mr. E's debts: "
              << SumArray(pd, 3) << std::endl;
    
    return 0;
}

template <typename T> T SumArray(T source[], int size)
{
    T sum;
    
    for (int i = 0; i < size; i++)
    {
        sum += source[i];
    }
    
    return sum;
}

template <typename T> T SumArray(T* source[], int size)
{
    T sum;
    
    for (int i = 0; i < size; i++)
    {
        sum += *source[i];
    }
    
    return sum;
}