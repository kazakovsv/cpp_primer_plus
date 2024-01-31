// Begin with the following structure declaration:
// struct chaff
// {
//     char dross[20];
//     int slag;
// };
// Write a program that uses placement new to place an array of two such
// structures in a buffer. Then assign values to the structure members
// (remembering to use strcpy() for the char array) and use a loop to display
// the contents. Option 1 is to use a static array, like that in Listing 9.10,
// for the buffer. Option 2 is to use regular new to allocate the buffer.

#include <iostream>
#include <cstring>
#include <new>

struct chaff
{
    char dross[20];
    int slag;
};

const int ChaffCount = 2;

char buffer[sizeof(chaff) * ChaffCount];

int main()
{
    chaff* v1 = new chaff[ChaffCount];
    chaff* v2 = new (buffer) chaff[ChaffCount];
    
    strcpy(v1[0].dross, "Dross");\
    v1[0].slag = 1;
    strcpy(v1[1].dross, "Dross");
    v1[1].slag = 2;
    
    strcpy(v2[0].dross, "Dross");
    v2[0].slag = 3;
    strcpy(v2[1].dross, "Dross");
    v2[1].slag = 4;
    
    std::cout << "Memory address of buffer: " << (void*) buffer << std::endl;
    
    for (int i = 0; i < ChaffCount; i++)
    {
        std::cout << "Chaff #" << i + 1 << std::endl;
        
        std::cout << "Version 1" << std::endl;
        std::cout << "Address: " << &v1[i] << " Values: " << v1[i].dross
                  << " - " << v1[i].slag << std::endl;
                  
        std::cout << "Version 2" << std::endl;
        std::cout << "Address: " << &v2[i] << " Values: " << v2[i].dross
                  << " - " << v2[i].slag << std::endl;
        
    }
    
    std::cout << "Done!" << std::endl;
    
    return 0;
}