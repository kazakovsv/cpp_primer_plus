// Write a program that has main() call a user-defined function that takes a
// distance in light years as an argument and then returns the distance in
// astronomical units.
// The program should request the light year value as input from the user and
// display the result, as shown in the following code:
// => Enter the number of light years: 4.2
// => 4.2 light years = 265608 astronomical units.
// 1 light year = 63,240 astronomical units

#include <iostream>

double light_years_to_astronomical_units(double);

int main()
{
    using namespace std;
    
    cout << "Enter the number of light years: ";
    double light_years;
    cin >> light_years;
    cout << light_years << " light years = "
         << light_years_to_astronomical_units(light_years)
         << " astronomical units." << endl;
    
    return 0;
}

double light_years_to_astronomical_units(double light_years)
{
    return light_years * 63240;
}
