// The CandyBar structure contains three members.The first member holds the
// brand name of a candy bar. The second member holds the weight (which may
// have a fractional part) of the candy bar, and the third member holds the
// number of calories (an integer value) in the candy bar. Write a program that
// uses a function that takes as arguments a reference to CandyBar, a
// pointer-to-char, a double, and an int and uses the last three values to set
// the corresponding members of the structure. The last three arguments should
// have default values of “Millennium Munch,” 2.85, and 350. Also the program
// should use a function that takes a reference to a CandyBar as an argument
// and displays the contents of the structure. Use const where appropriate.

#include <iostream>
#include <cstring>

struct candy_bar
{
    char brand[20];
    double weight;
    int calories;
};

void fill(candy_bar& cb, const char* brand = "Millennium Munch", double weight = 2.85, int calories = 350);
void show(const candy_bar& cb);

int main()
{
    std::cout << "Default:" << std::endl;
    candy_bar cb1 = {0};
    fill(cb1);
    show(cb1);
    
    std::cout << "User defined:" << std::endl;
    candy_bar cb2 = {0};
    fill(cb2, "Kit Kat", 1.5, 210);
    show(cb2);
    
    return 0;
}

void fill(candy_bar& cb, const char* brand, double weight, int calories)
{
    strcpy(cb.brand, brand);
    cb.weight = weight;
    cb.calories = calories;
}

void show(const candy_bar& cb)
{
    std::cout << "Brand: " << cb.brand << std::endl;
    std::cout << "Weight: " << cb.weight << std::endl;
    std::cout << "Calories: " << cb.calories << std::endl;
}