// Redo Listing 9.9, replacing the character array with a string object. The
// program should no longer have to check whether the input string fits, and it
// can compare the input string to "" to check for an empty line.

#include <iostream>
#include <string>

void strcount(std::string s);

int main()
{
    using namespace std;
    
    string input;
    cout << "Enter a line:" << endl;
    
    while (getline(cin, input) && input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):" << endl;
    }
    
    cout << "Bye\n";
    
    return 0;
}

void strcount(std::string s)
{
    using namespace std;
    
    static int total = 0;
    int count = s.size();
    
    cout << "\"" << s <<"\" contains ";
      
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}