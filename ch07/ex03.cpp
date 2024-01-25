// Here is a structure declaration:
// struct box
// {
//     char maker[40];
//     float height;
//     float width;
//     float length;
//     float volume;
// };
// a. Write a function that passes a box structure by value and that displays
// the value of each member.
// b. Write a function that passes the address of a box structure and that sets
// the volume member to the product of the other three dimensions.
// c. Write a simple program that uses these two functions.

#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void display_members(box b);
void calculate_volume(box* b);

int main()
{
    box b = {"The Box Factory", 15.0f, 15.0f, 15.0f, 0.0f};
    calculate_volume(&b);
    display_members(b);
    
    return 0;
}

void display_members(box b)
{
    std::cout << "Members of the box:" << std::endl;
    std::cout << "Maker: " << b.maker << std::endl;
    std::cout << "Height: " << b.height << std::endl;
    std::cout << "Width: " << b.width << std::endl;
    std::cout << "Length: " << b.length << std::endl;
    std::cout << "Volume: " << b.volume << std::endl;
}

void calculate_volume(box* b)
{
    b->volume = b->height * b->width * b->length;
}

