// Here is a rather simple class definition:
// class Person {
// private:
//     static const LIMIT = 25;
//     string lname; // Person’s last name
//     char fname[LIMIT]; // Person’s first name
// public:
//     Person() {lname = ""; fname[0] = '\0'; } // #1
//     Person(const string & ln, const char * fn = "Heyyou"); // #2
//     // the following methods display lname and fname
//     void Show() const; // firstname lastname format
//     void FormalShow() const; // lastname, firstname format
// };
// Write a program that completes the implementation by providing code for the
// undefined methods. The program in which you use the class should also use
// the three possible constructor calls (no arguments, one argument, and two
// arguments) and the two display methods.

#include <iostream>
#include <cstring>

class Person {
private:
    static const int LIMIT = 25;
    std::string m_last_name;
    char m_first_name[LIMIT];
public:
    Person() { m_last_name = ""; m_first_name[0] = '\0'; }
    Person(const std::string & last_name, const char * first_name = "Heyyou");
    void Show() const;
    void FormalShow() const;
};

Person::Person(const std::string & last_name, const char * first_name)
{
    m_last_name = last_name;
    strncpy(m_first_name, first_name, LIMIT - 1);
    m_first_name[LIMIT - 1] = '\0';
}

void Person::Show() const
{
    std::cout << m_first_name << " " << m_last_name << std::endl;
}

void Person::FormalShow() const
{
    std::cout << m_last_name << ", " << m_first_name << std::endl;
}

int main()
{
    Person p1;
    p1.Show();
    p1.FormalShow();
    
    std::cout << std::endl;
    
    Person p2("Smythecraft");
    p2.Show();
    p2.FormalShow();
    
    std::cout << std::endl;
    
    Person p3("Dimwiddy", "Sam");
    p3.Show();
    p3.FormalShow();
    
    return 0;
}