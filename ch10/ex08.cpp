// You can describe a simple list as follows:
// - The simple list can hold zero or more items of some particular type.
// - You can create an empty list.
// - You can add items to the list.
// - You can determine whether the list is empty.
// - You can determine whether the list is full.
// - You can visit each item in the list and perform some action on it.
// As you can see, this list really is simple; it doesn’t allow insertion or
// deletion, for example.
// Design a List class to represent this abstract type.You should provide a
// list.h header file with the class declaration and a list.cpp file with the
// class method implementations. You should also create a short program that
// utilizes your design.
// The main reason for keeping the list specification simple is to simplify
// this programming exercise. You can implement the list as an array or, if
// you’re familiar with the data type, as a linked list. But the public
// interface should not depend on your choice. That is, the public interface
// should not have array indices, pointers to nodes, and so on. It should be
// expressed in the general concepts of creating a list, adding an item to the
// list, and so on. The usual way to handle visiting each item and performing
// an action is to use a function that takes a function pointer as an argument:
// id visit(void (*pf)(Item &));
// Here pf points to a function (not a member function) that takes a reference
// to Item argument, where Item is the type for items in the list. The visit()
// function applies this function to each item in the list. You can use the
// Stack class as a general guide.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "list.h"

void Print(Item & item);

int main()
{
    srand(time(0));
    
    List list;
    
    for (int i = 0; i < 100; i++)
    {
        list.Add(rand());
    }
    
    list.Visit(Print);
    
    return 0;
}

void Print(Item & item)
{
    std::cout << item << std::endl;
}