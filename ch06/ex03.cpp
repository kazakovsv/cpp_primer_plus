// Write a precursor to a menu-driven program.The program should display a menu
// offering four choices, each labeled with a letter. If the user responds with
// a letter other than one of the four valid choices, the program should prompt
// the user to enter a valid response until the user complies.Then the program
// should use a switch to select a simple action based on the user’s selection.
// A program run could look something like this:
// => Please enter one of the following choices:
// => c) carnivore p) pianist
// => t) tree g) game
// => f
// => Please enter a c, p, t, or g: q
// => Please enter a c, p, t, or g: t
// => A maple is a tree.

#include <iostream>

int main()
{
    using namespace std;
    
    cout << "Please enter one of the following choices:" << endl
         << "c) carnivore p) pianist" << endl
         << "t) tree g) game" << endl;
    
    char c = '\0';
    cin >> c;
    
    while (c != 'c' && c != 'p' && c != 't' && c != 'g')
    {
       cout << "Please enter a c, p, t, or g: ";
       cin >> c;
    }
    
    switch (c)
    {
        case 'c':
            cout << "Mmm... delicious!" << endl;
            break;
        case 'p':
            cout << "Blah, blah, blah, blah, blah." << endl;
            break;
        case 't':
            cout << "A maple is a tree." << endl;
            break;
        case 'g':
            cout << "The game begins." << endl;
            break;
    }
    
    return 0;
}