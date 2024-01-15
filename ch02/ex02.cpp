// Write a C++ program that asks for a distance in furlongs and converts it to
// yards. (One furlong is 220 yards.)

#include <iostream>

int furlongs_to_yards(int);

int main()
{
    using namespace std;
    
    cout << "Enter the distance in furlongs: ";
    int distance;
    cin >> distance;
    cout << distance << " furlongs = "
         << furlongs_to_yards(distance)
         << " yards." << endl; 
    
    return 0;
}

int furlongs_to_yards(int distance)
{
    return distance * 220;
}
