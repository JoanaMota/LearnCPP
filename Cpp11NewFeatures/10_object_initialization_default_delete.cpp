#include <iostream>

class Test
{
private:
    int m_id{3};
    std::string m_name{"Joana"};

public:
    Test() = default;                             // Here we recover a functionality that we lost with the parameterized constructor
    Test(int f_id) : m_id(f_id){};                // Parameterized constructor
    Test(const Test &other) = default;            // here we are only emphasizing something that we already have
    Test &operator=(const Test &other) = default; // here we are only emphasising something that we already have
    ~Test(){};
    void print(void)
    {
        std::cout << m_id << ": " << m_name << std::endl;
    }
};

int main()
{
    Test test1;
    test1.print();
    Test test2(88);
    test2.print();

    Test test3 = test2;
    test3 = test1;
    return 0;
}