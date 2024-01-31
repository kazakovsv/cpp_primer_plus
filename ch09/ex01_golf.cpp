#include <iostream>
#include <cstring>
#include "ex01_golf.h"

void setgolf(golf& g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g)
{
    std::cout << "Enter a name: ";
    char* name = new char[Len];
    int result = 0;
    
    if(std::cin.get(name, Len) && name[0] != '\0')
    {
        while (std::cin.get() != '\n')
        {
            continue;
        }
        
        std::cout << "Enter a handicap: ";
        int hc = 0;
        
        while (!(std::cin >> hc))
        {
            std::cin.clear();
            
            while (std::cin.get() != '\n')
            {
                continue;
            }
            
            std::cout << "Enter an integer value: ";
        }
        
        while (std::cin.get() != '\n')
        {
            continue;
        }
        
        setgolf(g, name, hc);
        
        result = 1;
    }
    
    return result;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    std::cout << "Name: " << g.fullname;
    std::cout << ", Handicap: " << g.handicap << std::endl;
}