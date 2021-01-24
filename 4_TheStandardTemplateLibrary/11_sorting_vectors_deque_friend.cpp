#include <iostream>
#include <vector>
#include <algorithm> // std::sort

class CTest
{
private:
    int m_id;
    std::string m_name;

public:
    CTest(int f_id, std::string f_name) : m_id(f_id), m_name(f_name)
    {
        // std::cout << "Object " << m_name << " created" << std::endl;
    }
    ~CTest()
    {
        // std::cout << "Object " << m_name << " destroyed" << std::endl;
    }
    void print(void)
    {
        std::cout << m_id << " : " << m_name << std::endl;
    }
    bool operator<(const CTest &f_other) const
    {
        if (m_name == f_other.m_name)
        {
            return m_id < f_other.m_id;
        }
        else
        {
            return m_name < f_other.m_name;
        }
    }
    // Friends are allowed to access private members
    // When a function with this prototype is found it will be made a friend to this class
    friend bool compare(const CTest &a, const CTest &b);
};

bool compare(const CTest &a, const CTest &b)
{
    return a.m_name < b.m_name;
}

int main()
{
    std::cout << "----Sort with operator < overload----" << std::endl;
    std::vector<CTest> tests1;
    tests1.push_back(CTest(5, "Mike"));
    tests1.push_back(CTest(10, "Sue"));
    tests1.push_back(CTest(7, "Raj"));
    tests1.push_back(CTest(3, "Vicky"));
    tests1.push_back(CTest(4, "Raj"));

    std::cout << " Vector Unsorted " << std::endl;
    for (int it = 0; it < tests1.size(); it++)
    {
        tests1[it].print();
    }

    // Since this vector contains Objects sort does not know
    // how to sort these type of elements.
    // We need to create an operator overload for <
    std::sort(tests1.begin(), tests1.end());
    std::cout << " Vector Sorted " << std::endl;
    for (int it = 0; it < tests1.size(); it++)
    {
        tests1[it].print();
    }

    std::cout << "----Sort with function pointer with compare algorithm----" << std::endl;
    std::vector<CTest> tests2;
    tests2.push_back(CTest(5, "Mike"));
    tests2.push_back(CTest(10, "Sue"));
    tests2.push_back(CTest(7, "Raj"));
    tests2.push_back(CTest(3, "Vicky"));
    tests2.push_back(CTest(4, "Raj"));

    std::cout << " Vector Unsorted " << std::endl;
    for (int it = 0; it < tests2.size(); it++)
    {
        tests2[it].print();
    }

    // Since this vector contains Objects sort does not know
    // how to sort these type of elements.
    // We need to create an operator overload for <
    std::sort(tests2.begin(), tests2.end(), compare);
    std::cout << " Vector Sorted " << std::endl;
    for (int it = 0; it < tests2.size(); it++)
    {
        tests2[it].print();
    }

    return 0;
}