// Write a program that reads up to 10 donation values into an array of double.
// (Or, if you prefer, use an array template object.) The program should
// terminate input on non-numeric input. It should report the average of the
// numbers and also report how many numbers in the array are larger than the
// average.

#include <iostream>

const int MaxDonations = 10;

int main()
{
    using namespace std;
    
    cout << "Enter up to " << MaxDonations << " donations:" << endl;
    
    double donations[MaxDonations] = {};
    int count = 0;
    
    for (count = 0; count < MaxDonations; count++)
    {
        cout << "Donation #" << count + 1 << ": ";
        
        if (!(cin >> donations[count]))
        {
            break;
        }
    }
    
    if (count == 0)
    {
        cout << "No donations!" << endl;
    }
    else
    {
        double sum = 0;
    
        for (int i = 0; i < count; i++)
        {
            sum += donations[i];
        }
        
        double average = sum / count;
        
        cout << "The average of donations is " << average << endl;
        
        int big_donations = 0;
        
        for (int i = 0; i < count; i++)
        {
            if (donations[i] > average)
            {
                big_donations++;
            }
        }
        
        if (big_donations > 0)
        {
            cout << big_donations
                 << " donation(s) is(are) larger than the average."
                 << endl;
        }
    }
    
    return 0;
}