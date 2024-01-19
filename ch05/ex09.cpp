// Write a program that matches the description of the program in Programming
// Exercise 8, but use a string class object instead of an array. Include the
// string header file and use a relational operator to make the comparison test.

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    int word_count = 0;
    string word;
    
    cout << "Enter words (to stop, type the word done):" << endl;
    
    cin >> word;
    while (word != "done")
    {
        word_count++;
        cin >> word;
    }
    
    cout << "You entered a total of " << word_count << " words." << endl;
    
    return 0;
}