// Define a recursive function that takes an integer argument and returns the
// factorial of that argument. Recall that 3 factorial, written 3!, equals
// 3 × 2!, and so on, with 0! defined as 1. In general, if n is greater than
// zero, n! = n * (n - 1)!. Test your function in a program that uses a loop to
// allow the user to enter various values for which the program reports the
// factorial.

#include <iostream>

long long int factorial(int n);

int main()
{
    using namespace std;
    
    cout << "Enter an integer number (-1 to quit): ";
    int n = 0;
    
    while (cin >> n && n >= 0)
    {
        cout << "The factorial of your numbers is "
             << factorial(n) << endl;
        cout << "Next number (-1 to quit): ";
    }
    
    cout << "Bye!" << endl;
    
    return 0;
}

long long int factorial(int n)
{
    return n <= 0 ? 1 : n * factorial(n - 1);
}