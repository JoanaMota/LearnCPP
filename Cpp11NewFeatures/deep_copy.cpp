#include <iostream>

class ClassA
{
private:
    int m_age;
    std::string m_name;
    int *m_p;

public:
    ClassA(int age, std::string name) : m_age(age), m_name(name), m_p(new int){};
    ClassA(ClassA &other) // Deep Copy, without this we would get a core dump error with a double free() execution
    {
        m_age = other.m_age;
        m_name = other.m_name;
        m_p = new int;
        *m_p = *other.m_p;
    }
    ~ClassA()
    {
        delete m_p;
    };
    int getAge()
    {
        return m_age;
    }
    void setAge(int age)
    {
        m_age = age;
    }
};

int main()
{
    ClassA a(5, "Joana");
    ClassA b(a);

    std::cout << a.getAge() << std::endl;
    b.setAge(20);
    std::cout << a.getAge() << std::endl;
    std::cout << b.getAge() << std::endl;

    return 0;
}