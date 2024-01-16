// Write a short program that asks for your height in integer inches and then
// converts your height to feet and inches. Have the program use the underscore
// character to indicate where to type the response. Also use a const symbolic
// constant to represent the conversion factor.

#include <iostream>

int main()
{
    using namespace std;
    
    const int InchesPerFoot = 12;
    
    cout << "Enter your height in integer inches: __\b\b";
    int height;
    cin >> height;
    
    cout << height << " inches = "
         << height / InchesPerFoot << " feet and "
         << height % InchesPerFoot << " inches."
         << endl;
    
    return 0;
}
