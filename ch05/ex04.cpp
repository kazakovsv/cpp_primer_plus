// Daphne invests $100 at 10% simple interest.That is, every year, the
// investment earns 10% of the original investment, or $10 each and every year:
//     interest = 0.10 × original balance
// At the same time, Cleo invests $100 at 5% compound interest. That is,
// interest is 5% of the current balance, including previous additions of
// interest:
//     interest = 0.05 × current balance
// Cleo earns 5% of $100 the first year, giving her $105.The next year she
// earns 5% of $105, or $5.25, and so on. Write a program that finds how many
// years it takes for the value of Cleo’s investment to exceed the value of
// Daphne’s investment and then displays the value of both investments at that
// time.

#include <iostream>

const double SimpleInterest = 0.10;
const double CompoundInterest = 0.05;
const double OriginalBalance = 100.0;

int main()
{
    using namespace std;
    
    double daphne_balance = OriginalBalance;
    double cleo_balance = OriginalBalance;
    int year = 1;
    
    while (daphne_balance >= cleo_balance)
    {
        daphne_balance += SimpleInterest * OriginalBalance;
        cleo_balance += CompoundInterest * cleo_balance;
        
        cout << "Year " << year << " Daphne balance: $" << daphne_balance
             << " Cleo balance: $" << cleo_balance << endl;
        
        year++;
    }
    
    cout << "It took " << year - 1 << " years." << endl;
    
    return 0;
}