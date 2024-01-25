// This exercise provides practice in writing functions dealing with arrays and
// structures. The following is a program skeleton. Complete it by providing
// the described functions.

#include <iostream>

const int SLEN = 30;

struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int get_info(student students[], int size);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    std::cout << "Enter class size: ";
    int class_size;
    std::cin >> class_size;
    
    while (std::cin.get() != '\n')
    {
        continue;
    }
    
    student* p_students = new student[class_size];
    int entered = get_info(p_students, class_size);
    
    for (int i = 0; i < entered; i++)
    {
        display1(p_students[i]);
        display2(&p_students[i]);
    }
    
    display3(p_students, entered);
    delete [] p_students;
    std::cout << "Done!" << std::endl;
    
    return 0;
}

int get_info(student students[], int size)
{
    std::cout << "Enter infromation about the students in your class."
              << std::endl;
    
    int count = 0;
    
    while (count < size)
    {
        std::cout << "Student #" << count + 1 << std::endl;
        std::cout << "Name: ";
        std::cin.getline(students[count].fullname, SLEN);
        
        if (students[count].fullname[0] == '\0')
        {
            break;
        }
        
        std::cout << "Hobby: ";
        std::cin.getline(students[count].hobby, SLEN);
        std::cout << "OOP Level: ";
        (std::cin >> students[count].ooplevel).get();
        
        ++count;
    }
    
    return count;
}

void display1(student st)
{
    std::cout << "Fullname: " << st.fullname << std::endl;
    std::cout << "Hobby: " << st.hobby << std::endl;
    std::cout << "OOP Level: " << st.ooplevel << std::endl;
}

void display2(const student * ps)
{
    std::cout << "Fullname: " << ps->fullname << std::endl;
    std::cout << "Hobby: " << ps->hobby << std::endl;
    std::cout << "OOP Level: " << ps->ooplevel << std::endl;
}

void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Fullname: " << pa[i].fullname << std::endl;
        std::cout << "Hobby: " << pa[i].hobby << std::endl;
        std::cout << "OOP Level: " << pa[i].ooplevel << std::endl;
    }
}