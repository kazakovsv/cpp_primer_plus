// Write a program that repeatedly asks the user to enter pairs of numbers
// until at least one of the pair is 0. For each pair, the program should use
// a function to calculate the harmonic mean of the numbers. The function
// should return the answer to main(), which should report the result. The
// harmonic mean of the numbers is the inverse of the average of the inverses
// and can be calculated as follows:
// harmonic mean = 2.0 × x × y / (x + y).

#include <iostream>

double calculate_harmonic_mean(int x, int y);

int main()
{
    using namespace std;
    
    cout << "Enter pair of numbers (0 to quit): ";
    int x = 0;
    int y = 0;
    cin >> x >> y;
    
    while (x != 0 && y != 0)
    {
        cout << "The harmonic mean of the numbers is "
             << calculate_harmonic_mean(x, y) << endl;
        
        cout << "Next pair (0 to quit): ";
        cin >> x >> y;
    }
    
    cout << "Bye!" << endl;
    
    return 0;
}

double calculate_harmonic_mean(int x, int y)
{
    return 2.0 * x * y / (x + y);
}