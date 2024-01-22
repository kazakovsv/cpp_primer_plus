// Write a program that reads input a word at a time until a lone q is entered.
// The program should then report the number of words that began with vowels,
// the number that began with consonants, and the number that fit neither of
// those categories. One approach is to use isalpha() to discriminate between
// words beginning with letters and those that don’t and then use an if or
// switch statement to further identify those passing the isalpha() test that
// begin with vowels. A sample run might look like this:
// => Enter words (q to quit):
// => The 12 awesome oxen ambled
// => quietly across 15 meters of lawn. q
// => 5 words beginning with vowels
// => 4 words beginning with consonants
// => 2 others

#include <iostream>
#include <string>
#include <cctype>

int main()
{
    using namespace std;
    
    cout << "Enter words (q to quit):" << endl;
    
    string word;
    int vowels = 0;
    int consonants = 0;
    int others = 0;
    
    while (cin >> word && word != "q")
    {
        if (isalpha(word[0]))
        {
            switch (tolower(word[0]))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++vowels;
                    break;
                default:
                    ++consonants;
                    break;
            }
        }
        else
        {
            ++others;
        }
    }
    
    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;
    
    return 0;
}