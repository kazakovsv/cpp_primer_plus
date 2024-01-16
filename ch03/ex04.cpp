// Write a program that asks the user to enter the number of seconds as an
// integer value (use type long, or, if available, long long) and that then
// displays the equivalent time in days, hours, minutes, and seconds. Use
// symbolic constants to represent the number of hours in the day, the number
// of minutes in an hour, and the number of seconds in a minute.The output
// should look like this:
// => Enter the number of seconds: 31600000
// => 31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds

#include <iostream>

int main()
{
    using namespace std;
    
    const int HoursPerDay = 24;
    const int MinutesPerHour = 60;
    const int SecondsPerMinute = 60;
    
    cout << "Enter the number of seconds: ";
    long long input_seconds;
    cin >> input_seconds;
    
    long long temp = input_seconds;
    int seconds = int(temp % SecondsPerMinute);
    temp = temp / SecondsPerMinute;
    int minutes = int(temp % MinutesPerHour);
    temp = temp / MinutesPerHour;
    int hours = int(temp % HoursPerDay);
    int days = int(temp / HoursPerDay);
    
    cout << input_seconds << " seconds = "
         << days << " days, "
         << hours << " hours, "
         << minutes << " minutes, "
         << seconds << " seconds." << endl;
    
    return 0;
}
