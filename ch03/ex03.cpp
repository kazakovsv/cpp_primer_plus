// Write a program that asks the user to enter a latitude in degrees, minutes,
// and seconds and that then displays the latitude in decimal format.There are
// 60 seconds of arc to a minute and 60 minutes of arc to a degree; represent
// these values with symbolic constants.You should use a separate variable for
// each input value.A sample run should look like this:
// => Enter a latitude in degrees, minutes, and seconds:
// => First, enter the degrees: 37
// => Next, enter the minutes of arc: 51
// => Finally, enter the seconds of arc: 19
// => 37 degrees, 51 minutes, 19 seconds = 37.8553 degrees

#include <iostream>

double convert(double, double, double);

int main()
{
    using namespace std;
    
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    
    cout << "First, enter the degrees: ";
    int degrees;
    cin >> degrees;
    
    cout << "Next, enter the minutes of arc: ";
    int minutes;
    cin >> minutes;
    
    cout << "Finally, enter the seconds of arc: ";
    int seconds;
    cin >> seconds;
    
    cout << degrees << " degrees, "
         << minutes << " minutes, "
         << seconds << " seconds = "
         << convert(seconds, minutes, degrees) << " degrees." << endl;
    
    return 0;
}

double convert(double seconds, double minutes, double degrees)
{ 
    const int SecondsPerMinute = 60;
    const int MinutesPerDegree = 60;
    
    return (((seconds / SecondsPerMinute) + minutes) / MinutesPerDegree) + degrees;
}
