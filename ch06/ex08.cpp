// Write a program that opens a text file, reads it character-by-character to
// the end of the file, and reports the number of characters in the file.

#include <cstdlib>
#include <iostream>
#include <fstream>

const int MaxLength = 256;

int main()
{
    using namespace std;
    
    cout << "Enter file name: ";
    char file_name[MaxLength];
    cin.getline(file_name, MaxLength);
    
    ifstream fin;
    fin.open(file_name);
    
    if (!fin.is_open())
    {
        cout << "Could not open the file " << file_name << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char c;
    
    while (fin.get(c))
    {
        ++count;
    }
    
    fin.close();
    
    cout << "File contains " << count << " characters." << endl;
    
    return 0;
}