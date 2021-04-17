#ifndef RING_HPP
#define RING_HPP
#include <iostream>

template <class Type>
class CRing
{
private:
    int m_size;
    Type *m_values;
    int m_position;

public:
    class CIterator;
    CRing(int f_size) : m_size(f_size), m_values(NULL), m_position(0)
    {
        m_values = new Type[f_size];
    };
    ~CRing()
    {
        delete[] m_values;
    };
    int size(void)
    {
        return m_size;
    }
    CIterator begin(void)
    {
        return CIterator(0, *this);
    }
    CIterator end(void)
    {
        return CIterator(m_size, *this);
    }
    void add(Type f_value)
    {
        m_values[m_position++] = f_value; // using the value and then increment
        if (m_position == m_size)
        {
            m_position = 0;
        }
    }
    // Return a reference to the buffer value
    // The user as to be the one responsible for checking that he is not
    // getting something out of range
    Type &get(int f_position)
    {
        return m_values[f_position];
    }
};

template <class Type>
class CRing<Type>::CIterator
{
private:
    int m_position;
    CRing &m_ring;

public:
    CIterator(int f_position, CRing &f_ring) : m_position(f_position), m_ring(f_ring){};
    CIterator &operator++(int) // Suffix operator
    {
        m_position++;
        return *this;
    }
    CIterator &operator++() // Prefix operator
    {
        m_position++;
        return *this;
    }
    Type &operator*()
    {
        return m_ring.get(m_position);
    }
    bool operator!=(const CIterator &other) const
    {
        return m_position != other.m_position;
    }
    void print()
    {
        std::cout << "Hello from iterator" << std::endl;
    }
};

#endif /* RING_HPP */