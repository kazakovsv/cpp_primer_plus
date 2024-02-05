// Consider the following structure declaration:
// struct customer {
//     char fullname[35];
//     double payment;
// };
// Write a program that adds and removes customer structures from a stack,
// represented by a Stack class declaration. Each time a customer is removed,
// his or her payment should be added to a running total, and the running total
// should be reported. Note: You should be able to use the Stack class
// unaltered; just change the typedef declaration so that Item is type customer
// instead of unsigned long.

#include <iostream>
#include <cctype>

const int LIMIT = 35;

struct Customer {
    char name[LIMIT];
    double payment;
};

typedef Customer Item;

class Stack
{
private:
    enum { MAX = 10 };
    Item m_items[MAX];
    int m_top;
public:
    Stack();
    bool IsEmpty() const;
    bool IsFull() const;
    bool Push(const Item & item);
    bool Pop(Item & item);
};

Stack::Stack()
{
    m_top = 0;
}

bool Stack::IsEmpty() const
{
    return m_top == 0;
}

bool Stack::IsFull() const
{
    return m_top == MAX;
}

bool Stack::Push(const Item & item)
{
    if (m_top < MAX)
    {
        m_items[m_top++] = item;
        
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::Pop(Item & item)
{
    if (m_top > 0)
    {
        item = m_items[--m_top];
        
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Stack stack;
    double running_payment = 0.0;
    
    std::cout << "Please enter A to add a customer to stack," << std::endl;
    std::cout << "P to remove a customer from stack, or Q to quit." << std::endl;
    
    char choice;
    
    while (std::cin >> choice && toupper(choice) != 'Q')
    {
        while (std::cin.get() != '\n')
        {
            continue;
        }
        
        if (!isalpha(choice))
        {
            std::cout << '\a';
            
            continue;
        }
        
        switch(choice)
        {
        case 'A':
        case 'a':
            if (stack.IsFull())
            {
                std::cout << "Stack already full" << std::endl;
            }
            else
            {
                Customer customer;
                std::cout << "Enter a cutomer name: ";
                std::cin.getline(customer.name, LIMIT);
                std::cout << "Enter a payment: ";
                (std::cin >> customer.payment).get();
                running_payment += customer.payment;
                stack.Push(customer);
                std::cout << "Running payment: " << running_payment << std::endl;
            }
            
            break;
        case 'P':
        case 'p':
            if (stack.IsEmpty())
            {
                std::cout << "Stack already empty" << std::endl;
            }
            else
            {
                Customer customer;
                stack.Pop(customer);
                std::cout << "Customer: " << customer.name << " popped" << std::endl;
                running_payment -= customer.payment;
                std::cout << "Running payment: " << running_payment << std::endl;
            }
            
            break;
        }
        
        std::cout << "Please enter A to add a customer to stack," << std::endl;
        std::cout << "P to remove a customer from stack, or Q to quit." << std::endl;;
    }
    
    std::cout << "Bye" << std::endl;
    
    return 0;
}