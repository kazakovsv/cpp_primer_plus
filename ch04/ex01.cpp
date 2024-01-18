// Write a C++ program that requests and displays information as shown in the
// following example of output:
// => What is your first name? Betty Sue
// => What is your last name? Yewe
// => What letter grade do you deserve? B
// => What is your age? 22
// => Name: Yewe, Betty Sue
// => Grade: C
// => Age: 22
// Note that the program should be able to accept first names that comprise more
// than one word. Also note that the program adjusts the grade downward—that is,
// up one letter.Assume that the user requests an A, a B, or a C so that you
// don’t have to worry about the gap between a D and an F.

#include <iostream>

int main()
{
    using namespace std;
    
    const int Size = 20;
    
    cout << "What is your first name? ";
    char first_name[Size];
    cin.getline(first_name, Size);
    
    cout << "What is your last name? ";
    char last_name[Size];
    cin.getline(last_name, Size);
    
    cout << "What letter grade do you deserve? ";
    char grade;
    cin.get(grade).get();
    
    cout << "What is your age? ";
    int age;
    cin >> age;
    
    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << char (grade + 1) << endl;
    cout << "Age: " << age << endl;
    
    return 0;
}
