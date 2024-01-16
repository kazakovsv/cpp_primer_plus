// Write a short program that asks for your height in feet and inches and your
// weight in pounds. (Use three variables to store the information.) Have the
// program report your body mass index (BMI).To calculate the BMI, first
// convert your height in feet and inches to your height in inches (1 foot =
// 12 inches).Then convert your height in inches to your height in meters by
// multiplying by 0.0254.Then convert your weight in pounds into your mass in
// kilograms by dividing by 2.2. Finally, compute your BMI by dividing your
// mass in kilograms by the square of your height in meters. Use symbolic
// constants to represent the various conversion factors.

#include <iostream>

double bmi(double, double);

int main()
{
    using namespace std;
    
    const double InchesPerFoot = 12.0;
    const double MetersPerInch = 0.0254;
    const double PoundsPerKilogram = 2.2;
    
    cout << "Enter your height in feet and inches." << endl;
    cout << "-> feet: ";
    int feet;
    cin >> feet;
    cout << "-> inches: ";
    int inches;
    cin >> inches;
    
    cout << "Enter your weight in pounds: ";
    int pounds;
    cin >> pounds;
    
    double height = (feet * InchesPerFoot + inches) * MetersPerInch;
    double weight = pounds / PoundsPerKilogram;
    
    cout << "Your BMI is " << bmi(height, weight) << "." << endl;
    
    return 0;
}

double bmi(double height, double weight)
{
    return weight / (height * height);
}
