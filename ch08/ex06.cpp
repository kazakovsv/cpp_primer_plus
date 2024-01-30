// Write a template function maxn() that takes as its arguments an array of
// items of type T and an integer representing the number of elements in the
// array and that returns the largest item in the array. Test it in a program
// that uses the function template with an array of six int value and an array
// of four double values. The program should also include a specialization that
// takes an array of pointers-to-char as an argument and the number of pointers
// as a second argument and that returns the address of the longest string. If
// multiple strings are tied for having the longest length, the function should
// return the address of the first one tied for longest. Test the
// specialization with an array of five string pointers.

#include <iostream>
#include <cstring>

template <typename T> T maxn(T source[], int size);
template <> const char* maxn(const char* source[], int size);

int main()
{
    int arr1[6] {1, 2, 3, 4, 5, 6};
    double arr2[4] {5.23, 1.23, 4.11, 3.98};
    const char* arr3[5] =
    {
        "One",
        "Two",
        "Three",
        "Four",
        "Five"
    };
    
    std::cout << "Max of arr1: " << maxn(arr1, 6) << std::endl;
    std::cout << "Max of arr2: " << maxn(arr2, 4) << std::endl;
    std::cout << "Max of arr3: " << maxn(arr3, 5) << std::endl;
    
    return 0;
}

template <typename T> T maxn(T source[], int size)
{
    T max = source[0];
    
    for (int i = 1; i < size; i++)
    {
        if (source[i] > max)
        {
            max = source[i];
        }
    }
    
    return max;
}

template <> const char* maxn(const char* source[], int size)
{
    const char* max = source[0];
    
    for (int i = 1; i < size; i++)
    {
        if (strlen(source[i]) > strlen(max))
        {
            max = source[i];
        }
    }
    
    return max;
}