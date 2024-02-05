// A Betelgeusean plorg has these properties:
// Data
// - A plorg has a name with no more than 19 letters.
// - A plorg has a contentment index (CI), which is an integer.
// Operations
// - A new plorg starts out with a name and a CI of 50.
// - A plorg’s CI can change.
// - A plorg can report its name and CI.
// - The default plorg has the name "Plorga".
// Write a Plorg class declaration (including data members and member function
// prototypes) that represents a plorg. Write the function definitions for the
// member functions. Write a short program that demonstrates all the features
// of the Plorg class.

#include <iostream>
#include <cstring>

class Plorg
{
private:
    char m_name[20];
    int m_ci;
public:
    Plorg(const char * name = "Plorga", int ci = 50);
    void Show() const;
    void SetCI(int ci);
};

Plorg::Plorg(const char * name, int ci)
{
    strncpy(m_name, name, 19);
    m_name[19] = '\0';
    m_ci = ci;
}

void Plorg::Show() const
{
    std::cout << "Name: " << m_name << ", CI: " << m_ci << std::endl;
}

void Plorg::SetCI(int ci)
{
    m_ci = ci;
}

int main()
{
    Plorg p1;
    p1.Show();
    Plorg p2("Boga", 75);
    p2.Show();
    p1.SetCI(125);
    p1.Show();
    
    return 0;
}