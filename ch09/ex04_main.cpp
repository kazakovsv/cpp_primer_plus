// Write a three-file program based on the following namespace:
// namespace SALES
// {
//     const int QUARTERS = 4;
//     struct Sales
//     {
//         double sales[QUARTERS];
//         double average;
//         double max;
//         double min;
//     };
//     // copies the lesser of 4 or n items from the array ar
//     // to the sales member of s and computes and stores the
//     // average, maximum, and minimum values of the entered items;
//     // remaining elements of sales, if any, set to 0
//     void setSales(Sales & s, const double ar[], int n);
//     // gathers sales for 4 quarters interactively, stores them
//     // in the sales member of s and computes and stores the
//     // average, maximum, and minimum values
//     void setSales(Sales & s);
//     // display all information in structure s
//     void showSales(const Sales & s);
// }
// The first file should be a header file that contains the namespace.The
// second file should be a source code file that extends the namespace to
// provide definitions for the three prototyped functions. The third file
// should declare two Sales objects. It should use the interactive version of
// setSales() to provide values for one structure and the non-interactive
// version of setSales() to provide values for the second structure. It should
// display the contents of both structures by using showSales().

#include "ex04_sales.h"

int main()
{
    SALES::Sales s1;
    SALES::Sales s2;
    double sales[] = {1234.56, 2345.67, 3456.78, 4567.89, 5678.90};
    
    SALES::setSales(s1);
    SALES::setSales(s2, sales, 5);
    
    SALES::showSales(s1);
    SALES::showSales(s2);
    
    return 0;
}