#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : m_capacity(10), m_topI(-1)
{
    m_data = new int[m_capacity];
}

Stack::~Stack()
{
    delete[] m_data;
}

Stack::Stack(const Stack& other) : m_capacity(other.m_capacity), m_topI(other.m_topI)
{
    m_data = new int[m_capacity];
    for (int i = 0; i <= m_topI; ++i)
    {
        m_data[i] = other.m_data[i];
    }
}

Stack& Stack::operator=(const Stack& other)
{
    if (this == &other)
        return *this;

    delete[] m_data;

    m_capacity = other.m_capacity;
    m_topI = other.m_topI;
    m_data = new int[m_capacity];
    for (int i = 0; i <= m_topI; ++i)
    {
        m_data[i] = other.m_data[i];
    }

    return *this;
}

void Stack::resize()
{
    m_capacity *= 2;
    int* newData = new int[m_capacity];
    for (int i = 0; i <= m_topI; ++i)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
}

void Stack::push(int elem)
{
    if (m_topI + 1 == m_capacity)
    {
        resize();
    }
    m_data[++m_topI] = elem;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cerr << "Stack is empty. " << endl;
        return -1;
    }
    return m_data[m_topI--];
}

bool Stack::isEmpty() const
{
    return m_topI == -1;
}

void Stack::multiPop(int N)
{
    for (int i = 0; i < N && !isEmpty(); ++i)
    {
        pop();
    }
}

void Stack::show() const
{
    for (int i = 0; i <= m_topI; ++i)
    {
        cout << m_data[i] << " ";
    }
    cout << endl;
}
