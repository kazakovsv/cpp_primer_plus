// Write a program that uses the following functions:
// Fill_array() takes as arguments the name of an array of double values and an
// array size. It prompts the user to enter double values to be entered in the
// array. It ceases taking input when the array is full or when the user enters
// non-numeric input, and it returns the actual number of entries.
// Show_array() takes as arguments the name of an array of double values and an
// array size and displays the contents of the array.
// Reverse_array() takes as arguments the name of an array of double values and
// an array size and reverses the order of the values stored in the array.
// The program should use these functions to fill an array, show the array,
// reverse the array, show the array, reverse all but the first and last
// elements of the array, and then show the array.

#include <iostream>

const int Size = 10;

int fill_array(double target_array[], int size);
void show_array(const double target_array[], int size);
void reverse_array(double target_array[], int size);

int main()
{
    using namespace std;
    
    double target_array[Size] = {};
    int count = fill_array(target_array, Size);
    
    if (count >= 2)
    {
        cout << "Before reverse:" << endl;
        show_array(target_array, count);
        
        reverse_array(target_array + 1, count - 2);
        
        cout << "After reverse (except the first and last):" << endl;
        show_array(target_array, count);
    }
    
    return 0;
}

int fill_array(double target_array[], int size)
{
    std::cout << "Enter up to "<< size << " floating point numbers (q to quit):"
              << std::endl;
    
    int count = 0;
    double n = 0;
    
    for (; count < size; count++)
    {
        std::cout << "Number #" << count + 1 << ": ";
        
        if (!(std::cin >> n))
        {
            break;
        }
        
        target_array[count] = n;
    }
    
    return count;
}

void show_array(const double target_array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << " " << target_array[i];
    }
    
    std::cout << std::endl;
}

void reverse_array(double target_array[], int size)
{
    double temp;
    
    for (int i = 0; i < size / 2; i++)
    {
        temp = target_array[i];
        target_array[i] = target_array[size - i - 1];
        target_array[size - i - 1] = temp;
    }
}