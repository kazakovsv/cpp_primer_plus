// Design a function calculate() that takes two type double values and a
// pointer to a function that takes two double arguments and returns a double.
// The calculate() function should also be type double, and it should return
// the value that the pointed-to function calculates, using the double
// arguments to calculate(). For example, suppose you have this definition for
// the add() function:
// double add(double x, double y)
// {
//     return x + y;
// }
// Then, the function call in the following would cause calculate() to pass the
// values 2.5 and 10.4 to the add() function and then return the add() return
// value (12.9):
// double q = calculate(2.5, 10.4, add);
// Use these functions and at least one additional function in the add() mold
// in a program. The program should use a loop that allows the user to enter
// pairs of numbers. For each pair, use calculate() to invoke add() and at
// least one other function. If you are feeling adventurous, try creating an
// array of pointers to add()-style functions and use a loop to successively
// apply calculate() to a series of functions by using these pointers.
// Hint: Here’s how to declare such an array of three pointers:
// double (*pf[3])(double, double);
// You can initialize such an array by using the usual array initialization
// syntax and function names as addresses.

#include <iostream>

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

double calculate(double x, double y, double (*action)(double x, double y));

const int ActionsSize = 4;

int main()
{
    using namespace std;
    
    char action_symbols[ActionsSize] = { '+', '-', '*', '/' };
    
    double (*actions[ActionsSize])(double, double) =
    {
        add,
        sub,
        mul,
        div
    };
    
    cout << "Enter pair of numbers (q to quit): ";
    
    double x;
    double y;
    double result;
    
    while (cin >> x && cin >> y)
    {
        for (int i = 0; i < ActionsSize; i++)
        {
            result = actions[i](x, y);
            cout << x << " " << action_symbols[i]
                 << " " << y << " = " << result << endl;
        }
        
        cout << endl << "Next pair (q to quit): ";
    }
    
    cout << "Bye!" << endl;
    
    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double mul(double x, double y)
{
    return x * y;
}

double div(double x, double y)
{
    return y == 0 ? 0 : x / y;
}

double calculate(double x, double y, double (*action)(double x, double y))
{
    return action(x, y);
}