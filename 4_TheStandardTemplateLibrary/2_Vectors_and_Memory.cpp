#include <iostream>
#include <vector>

int main()
{
    std::vector<double> numbers(0);

    std::cout << numbers.capacity() << std::endl;

    for (int i = 0; i < 1000; i++)
    {
        numbers.push_back(i);
    }
    std::cout << "Vector Size: " << numbers.size() << std::endl;
    std::cout << "Vector Capacity: " << numbers.capacity() << std::endl;

    // Resize updates the vector size up or down
    numbers.resize(2000);
    std::cout << "Vector Size: " << numbers.size() << std::endl;
    std::cout << "Vector Capacity: " << numbers.capacity() << std::endl;
    numbers.resize(10);
    std::cout << "Vector Size: " << numbers.size() << std::endl;
    std::cout << "Vector Capacity: " << numbers.capacity() << std::endl;

    // Reserve updates the vector capacity only up
    numbers.reserve(4000);
    std::cout << "Vector Size: " << numbers.size() << std::endl;
    std::cout << "Vector Capacity: " << numbers.capacity() << std::endl;
    numbers.reserve(10);
    std::cout << "Vector Size: " << numbers.size() << std::endl;
    std::cout << "Vector Capacity: " << numbers.capacity() << std::endl;

    return 0;
}
