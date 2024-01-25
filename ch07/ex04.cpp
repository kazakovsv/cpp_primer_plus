// Many state lotteries use a variation of the simple lottery portrayed by
// Listing 7.4. In these variations you choose several numbers from one set and
// call them the field numbers. For example, you might select five numbers from
// the field of 1–47). You also pick a single number (called a mega number or a
// power ball, etc.) from a second range, such as 1–27. To win the grand prize,
// you have to guess all the picks correctly. The chance of winning is the
// product of the probability of picking all the field numbers times the
// probability of picking the mega number. For instance, the probability of
// winning the example described here is the product of the probability of
// picking 5 out of 47 correctly times the probability of picking 1 out of 27
// correctly. Modify Listing 7.4 to calculate the probability of winning this
// kind of lottery.

#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    
    double total, choices;
    double power_total, power_choices;
    
    cout << "Enter the total number of choices on the game card and" << endl
         << "the number of picks allowed (q to quit): ";
    
    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "Enter the total number of choices for the power ball and" << endl
         << "the number of picks allowed (q to quit): ";
    
        if ((cin >> power_total >> power_choices) && power_choices <= power_total)
        {
            cout << "You have one chance in ";
            cout << probability(total, choices) * probability(power_total, power_choices);
            cout << " of winning." << endl << endl;
        }
        else
        {
            break;
        }
        
        cout << "Enter the total number of choices on the game card and" << endl
             << "the number of picks allowed (q to quit): ";
    }
    
    cout << "Bye!" << endl;

    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    
    for (n = numbers, p = picks; p > 0; n--, p--)
    {
        result = result * n / p;
    }

    return result;
}