// Write a template function max5() that takes as its argument an array of five
// items of type T and returns the largest item in the array. (Because the size
// is fixed, it can be hard-coded into the loop instead of being passed as an
// argument.) Test it in a program that uses the function with an array of five
// int value and an array of five double values.

#include <iostream>

template <typename T> T max5(const T source[]);

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "The largest item in the array [1, 2, 3, 4, 5] is "
              << max5(arr1) << std::endl;
    
    double arr2[] = {3.12, 4.24, 76.9, 34.2, 17.8};
    std::cout << "The largest item in the array [3.12, 4.24, 76.9, 34.2, 17.8] is "
              << max5(arr2) << std::endl;
    
    return 0;
}

template <typename T> T max5(const T source[])
{
    T max = source[0];
    
    for (int i = 1; i < 5; i++)
    {
        if (source[i] > max)
        {
            max = source[i];
        }
    }
    
    return max;
}