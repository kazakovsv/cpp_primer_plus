// Do Programming Exercise 7 but use new to allocate a structure instead of
// declaring a structure variable.Also have the program request the pizza
// diameter before it requests the pizza company name.

#include <iostream>

struct Pizza
{
    char brand[20];
    int diameter;
    double weight;
};

int main()
{
    using namespace std;
    
    cout << "What diameter is your favorite pizza? ";
    Pizza* pizza = new Pizza;
    (cin >> pizza->diameter).get();
    
    cout << "What is it called? ";
    cin.getline(pizza->brand, sizeof (pizza->brand) / sizeof (pizza->brand[0]));
    
    cout << "What is it weight? ";
    cin >> pizza->weight;
    
    cout << "Brand: " << pizza->brand << endl
         << "Diameter: " << pizza->diameter << endl
         << "Weight: " << pizza->weight << endl;
     
    delete pizza;
    
    return 0;
}