// Do Programming Exercise 6 but modify it to get information from a file. The
// first item in the file should be the number of contributors, and the rest of
// the file should consist of pairs of lines, with the first line of each pair
// being a contributor's name and the second line being a contribution. That is,
// the file should look like this:
// => 4
// => Sam Stone
// => 2000
// => Freida Flass
// => 100500
// => Tammy Tubbs
// => 5000
// => Rich Raptor
// => 55000

#include <iostream>
#include <fstream>

const int MaxNameLength = 20;
const int MaxFileLength = 256;
const int GrandContribution = 10000;

struct contributor
{
    char name[MaxNameLength];
    double contribution;
};

int main()
{
    using namespace std;
    
    cout << "Enter file name: ";
    char file_name[MaxFileLength];
    cin.getline(file_name, MaxFileLength);
    
    ifstream fin;
    fin.open(file_name);
    
    if (!fin.is_open())
    {
        cout << "Could not open the file " << file_name << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    (fin >> count).get();
    
    contributor* contributors = new contributor[count];
    
    for (int i = 0; i < count; i++)
    {
        fin.getline(contributors[i].name, MaxNameLength);
        (fin >> contributors[i].contribution).get();
    }
    
    fin.close();
    
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