// Do Programming Exercise 1 from Chapter 9 but replace the code shown there
// with an appropriate golf class declaration. Replace setgolf(golf &, const
// char*, int) with a constructor with the appropriate argument for providing
// initial values. Retain the interactive version of setgolf() but implement it
// by using the constructor. (For example, for the code for setgolf(), obtain
// the data, pass the data to the constructor to create a temporary object, and
// assign the temporary object to the invoking object, which is *this.)

#include <iostream>
#include <cstring>

class Golf
{
private:
    static const int LIMIT = 40;
    char m_name[LIMIT];
    int m_handicap;
public:
    Golf() { m_name[0] = '\0'; m_handicap = 0; }
    Golf(const char * name, int handicap);
    int SetGolf();
    void Handicap(int handicap);
    void Show() const;
};



Golf::Golf(const char * name, int handicap)
{
    strncpy(m_name, name, LIMIT - 1);
    m_name[LIMIT - 1] = '\0';
    m_handicap = handicap;
}

int Golf::SetGolf()
{
    std::cout << "Enter a name: ";
    char* name = new char[LIMIT];
    int result = 0;
    
    if(std::cin.get(name, LIMIT) && name[0] != '\0')
    {
        while (std::cin.get() != '\n')
        {
            continue;
        }
        
        std::cout << "Enter a handicap: ";
        int handicap = 0;
        
        while (!(std::cin >> handicap))
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
        
        *this = Golf(name, handicap);
        
        result = 1;
    }
    
    return result;
}

void Golf::Handicap(int handicap)
{
    m_handicap = handicap;
}

void Golf::Show() const
{
    std::cout << "Name: " << m_name
              << ", Handicap: " << m_handicap << std::endl;
}

const int TeamSize = 5;

int main()
{
    Golf team[TeamSize];
    
    std::cout << "Enter up to " << TeamSize << " golf team members" << std::endl;
    std::cout << "(empty name to quit)" << std::endl;
    
    int i;
    
    for (i = 0; i < TeamSize; i++)
    {
        if (!team[i].SetGolf())
        {
            break;
        }
    }
    
    if (i > 0)
    {
        std::cout << "You entered:" << std::endl;
        
        for (int j = 0; j < i; j++)
        {
            team[j].Show();
        }
    }
    
    std::cout << "Done!" << std::endl;
    
    return 0;
}