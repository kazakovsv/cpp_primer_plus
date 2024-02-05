#include "list.h"

void List::Add(const Item & item)
{
    if (m_count != MAX)
    {
        m_storage[m_count++] = item;
    }
}

bool List::IsEmpty() const
{
    return m_count == 0;
}

bool List::IsFull() const
{
    return m_count == MAX;
}

void List::Visit(void (*action)(Item &))
{
    for (int i = 0; i < m_count; i++)
    {
        action(m_storage[i]);
    }
}