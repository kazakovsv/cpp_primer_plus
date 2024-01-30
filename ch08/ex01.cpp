// Write a function that normally takes one argument, the address of a string,
// and prints that string once. However, if a second, type int, argument is 
// provided and is nonzero, the function should print the string a number of 
// times equal to the number of times that function has been called at that 
// point. (Note that the number of times the string is printed is not equal to
// the value of the second argument; it is equal to the number of times the 
// function has been called.) Yes, this is a silly function, but it makes you
// use some of the techniques discussed in this chapter. Use the function in a
// simple program that demonstrates how the function works.

#include <iostream>

void print_string(const char* text, int flag = 0);

int times;

int main()
{
    const char* text = "This is a string.";
    
    print_string(text);
    print_string(text);
    print_string(text);
    print_string(text, 1);
    
    return 0;
}

void print_string(const char* text, int flag)
{
    if (flag == 0)
    {
        std::cout << text << std::endl;
    }
    else
    {
        while (times-- > 0)
        {
            std::cout << text << std::endl;
        }
    }
    
    times++;
}