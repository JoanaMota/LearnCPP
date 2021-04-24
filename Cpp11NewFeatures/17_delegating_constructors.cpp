#include <iostream>
class CBefore
{
private:
    int m_x, m_y, m_z;

public:
    CBefore() : m_x{0}, m_y{0}, m_z{0} {}

    CBefore(int f_z) : m_x{0}, m_y{0}, m_z(f_z) {}

    void show()
    {
        std::cout << m_x << ", " << m_y << ", " << m_z << std::endl;
    }
};
class CAfter
{
private:
    int m_x, m_y, m_z;

public:
    CAfter() : m_x{0}, m_y{0}, m_z{0} {}

    // Constructor delegation
    // This away we dont need to repeat the other members initialization
    CAfter(int f_z) : CAfter()
    {
        m_z = f_z;
    }

    void show()
    {
        std::cout << m_x << ", " << m_y << ", " << m_z << std::endl;
    }
};
int main()
{
    CBefore before(3);
    before.show();
    CAfter after(3);
    after.show();
    return 0;
}