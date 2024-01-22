// When you join the Benevolent Order of Programmers, you can be known at BOP
// meetings by your real name, your job title, or your secret BOP name.Write a
// program that can list members by real name, by job title, by secret name, or
// by a member’s preference. Base the program on the following structure:
// Benevolent Order of Programmers name structure
// struct bop {
//     char fullname[strsize]; // real name
//     char title[strsize]; // job title
//     char bopname[strsize]; // secret BOP name
//     int preference; // 0 = fullname, 1 = title, 2 = bopname
// };
// In the program, create a small array of such structures and initialize it to
// suitable values. Have the program run a loop that lets the user select from
// different alternatives:
// a. display by name b. display by title
// c. display by bopname d. display by preference
// q. quit
// Note that “display by preference” does not mean display the preference
// member; it means display the member corresponding to the preference number.
// For instance, if preference is 1, choice d would display the programmer’s
// job title.A sample run may look something like the following:
// => Benevolent Order of Programmers Report
// => a. display by name b. display by title
// => c. display by bopname d. display by preference
// => q. quit
// => Enter your choice: a
// => Wimp Macho
// => Raki Rhodes
// => Celia Laiter
// => Hoppy Hipman
// => Pat Hand
// => Next choice: d
// => Wimp Macho
// => Junior Programmer
// => MIPS
// => Analyst Trainee
// => LOOPY
// => Next choice: q
// => Bye!

#include <iostream>

const int StringSize = 20;

struct bop {
    char fullname[StringSize];
    char title[StringSize];
    char bopname[StringSize];
    int preference;
};

int main()
{
    using namespace std;
    
    cout << "Benevolent Order of Programmers Report" << endl
         << "a. display by name b. display by title" << endl
         << "c. display by bopname d. display by preference" << endl
         << "q. quit" << endl;
    
    bop bops[] = 
    {
        {"Bruce Wayne", "Industrialist", "Batman", 0},
        {"Peter Parker", "Student", "Spiderman", 1},
        {"Clark Kent", "Journalist", "Superman", 2},
        {"Anthony Stark", "Inventor", "Iron Man", 0},
        {"Diana Prince", "Assistant Secretary", "Wonder Woman", 1}
    };
    
    char c = '\0';
    
    while ((c = cin.get()) != 'q')
    {
        if (c < 'a' || c > 'd')
        {
            cout << "Please enter a a, b, c, d, or q: ";
        }
        else
        {
            int bop_size = sizeof bops / sizeof bops[0];
            
            switch (c)
            {
                case 'a': 
                    for (int i = 0; i < bop_size; i++)
                    {
                        cout << bops[i].fullname << endl;
                    }
                    break;
                case 'b':
                    for (int i = 0; i < bop_size; i++)
                    {
                        cout << bops[i].title << endl;
                    }
                    break;
                case 'c':
                    for (int i = 0; i < bop_size; i++)
                    {
                        cout << bops[i].bopname << endl;
                    }
                    break;
                case 'd': 
                    for (int i = 0; i < bop_size; i++)
                    {
                        switch (bops[i].preference)
                        {
                            case 0: cout << bops[i].fullname << endl; break;
                            case 1: cout << bops[i].title << endl; break;
                            case 2: cout << bops[i].bopname << endl; break;
                        }
                    }
                    break;
            }
            
            cout << "Next choice: ";
        }
        
        while ((c = cin.get()) != '\n')
            continue;
    }
    
    cout << "Bye!" << endl;
    
    return 0;
}