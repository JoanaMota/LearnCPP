#include <iostream>

template <class T, class U, int I>
struct Test
{
    Test()
    {
        std::cout << "Primary template" << std::endl;
    }
};
// Partial Specialization
template <class T, int I>
struct Test<T, T *, I>
{
    Test()
    {
        std::cout << "Partial specialization 1" << std::endl;
    }
};
template <class T, class U, int I>
struct Test<T *, U, I>
{
    Test()
    {
        std::cout << "Partial specialization 2" << std::endl;
    }
};
template <class T>
struct Test<int, T *, 10>
{
    Test()
    {
        std::cout << "Partial specialization 3" << std::endl;
    }
};
template <class T, class U, int I>
struct Test<T, U *, I>
{
    Test()
    {
        std::cout << "Partial specialization 4" << std::endl;
    }
};

int main()
{
    Test<int, int, 10> t1;       // Primary template
    Test<float, float *, 10> t2; // Partial Specialization <T, T *, I>
    Test<int *, float, 10> t3;   // Partial Specialization <T *, U, I>
    Test<int, char *, 10> t4;    // Partial Specialization <int, T *, 10>
    Test<float, char *, 10> t5;  // Partial Specialization <T, U *, I>
    return 0;
}