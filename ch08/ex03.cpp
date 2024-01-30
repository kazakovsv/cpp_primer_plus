// Write a function that takes a reference to a string object as its parameter
// and that converts the contents of the string to uppercase. Use the toupper()
// function described in Table 6.4 of Chapter 6. Write a program that uses a
// loop which allows you to test the function with different input. A sample
// run might look like this:
// => Enter a string (q to quit): go away
// => GO AWAY
// => Next string (q to quit): good grief!
// => GOOD GRIEF!
// => Next string (q to quit): q
// => Bye.

#include <iostream>
#include <string>
#include <cctype>

void convert_to_uppercase(std::string& source);

int main()
{
    std::cout << "Enter a string (q to quit): ";
    std::string input;
    
    while (getline(std::cin, input) && input != "q")
    {
        convert_to_uppercase(input);
        std::cout << input << std::endl;
        std::cout << "Next string (q to quit): ";
    }
    
    std::cout << "Bye." << std::endl;
    
    return 0;
}

void convert_to_uppercase(std::string& source)
{
    for (int i = 0; i < source.size(); i++)
    {
        source[i] = toupper(source[i]);
    }
}