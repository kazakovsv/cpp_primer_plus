// Do Programming Exercise 5 but use a two-dimensional array to store input for
// 3 years of monthly sales. Report the total sales for each individual year
// and for the combined years.

#include <iostream>

const int MonthsPerYear = 12;
const int NumberOfYears = 3;

int main()
{
    using namespace std;
    
    const char* months[MonthsPerYear] =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    
    int sales_per_year[NumberOfYears][MonthsPerYear] = {};
    
    for (int i = 0; i < NumberOfYears; i++)
    {
        cout << "Enter salse for the " << i + 1 << " year:" << endl;
        
        for (int j = 0; j < MonthsPerYear; j++)
        {
            cout << months[j] << ": ";
            cin >> sales_per_year[i][j];
        }
        
        cout << endl;
    }
    
    int total_sales = 0;
    
    for (int i = 0; i < NumberOfYears; i++)
    {
        int current_total = 0;
        
        for (int j = 0; j < MonthsPerYear; j++)
        {
            current_total += sales_per_year[i][j];
        }
        
        cout << "Total sales for the " << i + 1 << " year is "
             << current_total << "." << endl;
        
        total_sales += current_total;
    }
    
    cout << "Total sales for all years is " << total_sales << "." << endl;
    
    return 0;
}