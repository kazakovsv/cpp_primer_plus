// Write a program that asks how many miles you have driven and how many
// gallons of gasoline you have used and then reports the miles per gallon your
// car has gotten. Or, if you prefer, the program can request distance in
// kilometers and petrol in liters and then report the result European style,
// in liters per 100 kilometers.

#include <iostream>

int main()
{
    using namespace std;
    
    cout << "How many miles you have driven: ";
    double distance;
    cin >> distance;
    
    cout << "How many gallons of gasoline you have used: ";
    double gasoline_amount;
    cin >> gasoline_amount;
    
    cout << "Your car's fuel economy is "
         << distance / gasoline_amount
         << " MPG." << endl;
    
    return 0;
}
