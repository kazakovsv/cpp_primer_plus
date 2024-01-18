// The CandyBar structure contains three members, as described in Programming
// Exercise 5.Write a program that creates an array of three CandyBar
// structures, initializes them to values of your choice, and then displays the
// contents of each structure.

#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int calories;
};

int main()
{
    using namespace std;
    
    CandyBar candy_bars[] =
    {
        { "Mocha Munch", 2.3, 350 },
        { "Kit Kat", 1.5, 210 },
        { "Whatchamacallit", 1.6, 230 }
    };
    
    cout << "Brand: " << candy_bars[0].brand << endl
         << "Weight: " << candy_bars[0].weight << endl
         << "Calories: " << candy_bars[0].calories << endl;
         
    cout << "Brand: " << candy_bars[1].brand << endl
         << "Weight: " << candy_bars[1].weight << endl
         << "Calories: " << candy_bars[1].calories << endl;
         
    cout << "Brand: " << candy_bars[2].brand << endl
         << "Weight: " << candy_bars[2].weight << endl
         << "Calories: " << candy_bars[2].calories << endl;
    
    return 0;
}
