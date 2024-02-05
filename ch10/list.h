#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List
{
private:
    enum { MAX = 100 };
    int m_count;
    Item m_storage[MAX];
public:
    List() { m_count = 0; }
    void Add(const Item & item);
    bool IsEmpty() const;
    bool IsFull() const;
    void Visit(void (*action)(Item &));
};

#endif