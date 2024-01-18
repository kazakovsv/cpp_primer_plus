// Write a program that requests the user to enter three times for the 40-yd
// dash (or 40-meter, if you prefer) and then displays the times and the
// average. Use an array object to hold the data. (Use a built-in array if
// array is not available.)

#include <iostream>
#include <array>

int main()
{
    using namespace std;
    
    array<double, 3> results;
    
    cout << "Enter the first result: ";
    cin >> results[0];
    
    cout << "Enter the second result: ";
    cin >> results[1];
    
    cout << "Enter the third result: ";
    cin >> results[2];
    
    cout << "1st: " << results[0] << endl;
    cout << "2nd: " << results[1] << endl;
    cout << "3rd: " << results[2] << endl;
    cout << "Avergae: " << (results[0] + results[1] + results[2]) / 3 << endl;
    
    return 0;
}
