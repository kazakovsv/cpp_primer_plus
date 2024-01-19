// Write a program that asks the user to type in numbers.After each entry, the
// program should report the cumulative sum of the entries to date.The program
// should terminate when the user enters 0.

#include <iostream>

int main()
{
    using namespace std;
    
    int number = 0;
    int sum = 0;
    
    cout << "Enter an integer or 0 to quit: ";
    cin >> number;
    
    while (number != 0)
    {
        sum += number;
        cout << "The cumulative sum is " << sum << "." << endl;
        cout << "Enter the next integer or 0 to quit: ";
        cin >> number;
    }
    
    cout << "Done!" << endl;
    
    return 0;
}