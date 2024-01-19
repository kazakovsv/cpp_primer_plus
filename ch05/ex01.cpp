// Write a program that requests the user to enter two integers.The program
// should then calculate and report the sum of all the integers between and
// including the two integers. At this point, assume that the smaller integer
// is entered first. For example, if the user enters 2 and 9, the program
// should report that the sum of all the integers from 2 through 9 is 44.

#include <iostream>

int main()
{
    using namespace std;
    
    cout << "Enter the minimum number: ";
    int min = 0;
    cin >> min;
    
    cout << "Enter the maximum number: ";
    int max = 0;
    cin >> max;
    
    int sum = 0;
    
    for (int i = min; i <= max; i++)
    {
        sum += i;
    }
    
    cout << "The sum of all integers from " << min
         << " through " << max << " is " << sum << endl;
    
    return 0;
}