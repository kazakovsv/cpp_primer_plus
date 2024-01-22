// Put together a program that keeps track of monetary contributions to the
// Society for the Preservation of Rightful Influence. It should ask the user
// to enter the number of contributors and then solicit the user to enter the
// name and contribution of each contributor. The information should be stored
// in a dynamically allocated array of structures. Each structure should have
// two members: a character array (or else a string object) to store the name
// and a double member to hold the amount of the contribution. After reading
// all the data, the program should display the names and amounts donated for
// all donors who contributed $10,000 or more. This list should be headed by
// the label Grand Patrons.After that, the program should list the remaining
// donors. That list should be headed Patrons. If there are no donors in one of
// the categories, the program should print the word "none". Aside from
// displaying two categories, the program need do no sorting.

#include <iostream>

const int MaxLength = 20;
const int GrandContribution = 10000;

struct contributor
{
    char name[MaxLength];
    double contribution;
};

int main()
{
    using namespace std;
    
    cout << "Enter the number of contributors: ";
    int count = 0;
    (cin >> count).get();
    
    contributor* contributors = new contributor[count];
    
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        cout << "Contibutor #" << i + 1 << ":" << endl;
        cout << "Enter the name: ";
        cin.getline(contributors[i].name, MaxLength);
        cout << "Enter the cnotribution: ";
        (cin >> contributors[i].contribution).get();
    }
    
    cout << endl << "Grand Patrons:" << endl;
    int grand_patrons = 0;
    
    for (int i = 0; i < count; i++)
    {
        if (contributors[i].contribution >= GrandContribution)
        {
            cout << contributors[i].name << " "
                 << contributors[i].contribution << endl;
            
            ++grand_patrons;
        }
    }
    
    if (grand_patrons == 0)
    {
        cout << "none" << endl;
    }
    
    cout << endl << "Patrons:" << endl;
    
    if (grand_patrons == count)
    {
        cout << "none" << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            if (contributors[i].contribution < GrandContribution)
            {
                cout << contributors[i].name << " "
                     << contributors[i].contribution << endl;
            }
        }
    }
    
    delete [] contributors;
    
    return 0;
}