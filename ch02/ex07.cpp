// Write a program that asks the user to enter an hour value and a minute value.
// The main() function should then pass these two values to a type void
// function that displays the two values in the format shown in the following
// sample run:
// => Enter the number of hours: 9
// => Enter the number of minutes: 28
// => Time: 9:28

#include <iostream>

void print_time(int, int);

int main()
{
    using namespace std;
    
    cout << "Enter the number of hours: ";
    int hours;
    cin >> hours;
    
    cout << "Enter the number of minutes: ";
    int minutes;
    cin >> minutes;
    
    print_time(hours, minutes);
    
    return 0;
}

void print_time(int hours, int minutes)
{
    using namespace std;
    
    cout << "Time: " << hours << ":" << minutes << endl;
}
