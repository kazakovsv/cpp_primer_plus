// Write a program that asks the user to enter his or her first name and then
// last name, and that then constructs, stores, and displays a third string,
// consisting of the user’s last name followed by a comma, a space, and first
// name. Use char arrays and functions from the cstring header file.A sample
// run could look like this:
// => Enter your first name: Flip
// => Enter your last name: Fleming
// => Here’s the information in a single string: Fleming, Flip

#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    
    const int Size = 20;
    
    cout << "Enter your first name: ";
    char first_name[Size];
    cin.getline(first_name, Size);
    
    cout << "Enter your last name: ";
    char last_name[Size];
    cin.getline(last_name, Size);
    
    char full_name[2 * Size + 2];
    strcpy(full_name, last_name);
    strcat(full_name, ", ");
    strcat(full_name, first_name);
    
    cout << "Here's the information in a single string: "
         << full_name << endl;
    
    return 0;
}
