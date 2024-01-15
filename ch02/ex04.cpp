// Write a program that asks the user to enter his or her age.The program then
// should display the age in months:
// => Enter your age: 29
// => Your age in months is 348.

#include <iostream>

int years_to_months(int);

int main()
{
    using namespace std;
    
    cout << "Enter your age: ";
    int years;
    cin >> years;
    cout << "Your age in months is "
         << years_to_months(years)
         << "." << endl;
    
    return 0;
}

int years_to_months(int years)
{
    return years * 12;
}

