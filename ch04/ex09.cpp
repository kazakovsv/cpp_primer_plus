// Do Programming Exercise 6, but instead of declaring an array of three
// CandyBar structures, use new to allocate the array dynamically.

#include <iostream>
#include <cstring>

struct CandyBar
{
    char brand[20];
    double weight;
    int calories;
};

int main()
{
    using namespace std;
    
    CandyBar* candy_bars = new CandyBar[3];
    
    strcpy(candy_bars[0].brand, "Mocha Munch");
    candy_bars[0].weight = 2.3;
    candy_bars[0].calories = 350;
    
    strcpy(candy_bars[1].brand, "Kit Kat");
    candy_bars[1].weight = 1.5;
    candy_bars[1].calories = 210;
    
    strcpy(candy_bars[2].brand, "Whatchamacallit");
    candy_bars[2].weight = 1.6;
    candy_bars[2].calories = 230;
    
    cout << "Brand: " << candy_bars[0].brand << endl
         << "Weight: " << candy_bars[0].weight << endl
         << "Calories: " << candy_bars[0].calories << endl;
         
    cout << "Brand: " << candy_bars[1].brand << endl
         << "Weight: " << candy_bars[1].weight << endl
         << "Calories: " << candy_bars[1].calories << endl;
         
    cout << "Brand: " << candy_bars[2].brand << endl
         << "Weight: " << candy_bars[2].weight << endl
         << "Calories: " << candy_bars[2].calories << endl;
         
    delete [] candy_bars;
    
    return 0;
}
