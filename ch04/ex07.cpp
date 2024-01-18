// William Wingate runs a pizza-analysis service. For each pizza, he needs to
// record the following information:
//  - The name of the pizza company, which can consist of more than one word
//  - The diameter of the pizza
//  - The weight of the pizza
// Devise a structure that can hold this information and write a program that
// uses a structure variable of that type.The program should ask the user to
// enter each of the preceding items of information, and then the program
// should display that information. Use cin (or its methods) and cout.

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
    
    Pizza pizza;
    cout << "What is your favorite pizza? ";
    cin.getline(pizza.brand, sizeof (pizza.brand) / sizeof (pizza.brand[0]));
    
    cout << "What diameter is it? ";
    cin >> pizza.diameter;
    
    cout << "What is it weight? ";
    cin >> pizza.weight;
    
    cout << "Brand: " << pizza.brand << endl
         << "Diameter: " << pizza.diameter << endl
         << "Weight: " << pizza.weight << endl;
    
    return 0;
}
