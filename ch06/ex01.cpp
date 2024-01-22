// Write a program that reads keyboard input to the @ symbol and that echoes
// the input except for digits, converting each uppercase character to
// lowercase, and vice versa. (Don’t forget the cctype family.)

#include <iostream>
#include <cctype>

int main()
{
    using namespace std;
    
    cout << "Your input: ";
    char c;
    
    while ((c = cin.get()) != '@')
    {
        if (isdigit(c)) continue;
        
        if (islower(c))
        {
            c =  toupper(c);
        }
        else if (isupper(c))
        {
            c =  tolower(c);
        }
        
        cout << c;
    }
    
    return 0;
}