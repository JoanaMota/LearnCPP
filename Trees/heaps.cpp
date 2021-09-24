#include <iostream>
#include <vector>
#include <algorithm>
template <typename T>
void print(std::vector<T> &vec)
{
    for (T elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<double> numbers1 = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<int> numbers2 = {3, 1, 6, 5, 4, 0, 7, 9, 2, 8};
    std::cout << std::boolalpha << std::is_heap(begin(numbers1), end(numbers1)) << std::endl; // False
    std::make_heap(begin(numbers1), end(numbers1));
    print(numbers1); // 9 8 6 7 4 5 2 0 3 1
    std::make_heap(begin(numbers2), end(numbers2));
    print(numbers2); // 9 8 7 5 4 0 6 1 2 3

    std::cout << "Numbers1: " << std::boolalpha << std::is_heap(begin(numbers1), end(numbers1)) << std::endl; // True
    auto heapUntil = std::is_heap_until(begin(numbers1), end(numbers1));
    std::cout << "Numbers1 is heap until: " << *heapUntil << std::endl; // True

    std::vector<int> numbers3 = {9, 7, 5, 4, 0, 6, 1, 2, 3};
    std::cout << std::boolalpha << std::is_heap(begin(numbers3), end(numbers3)) << std::endl; // True
    auto heapUntil3 = std::is_heap_until(begin(numbers3), end(numbers3));
    std::cout << "Numbers3 is heap until: " << *heapUntil3 << std::endl; // True

    // Insert Element
    numbers1.push_back(8.8);
    std::push_heap(begin(numbers1), end(numbers1));
    print(numbers1); // 9 8.8 6 7 8 5 2 0 3 1 4

    numbers1.push_back(10);
    std::push_heap(begin(numbers1), end(numbers1));
    print(numbers1); // 10 8.8 9 7 8 6 2 0 3 1 4 5

    numbers1.push_back(9);
    std::push_heap(begin(numbers1), end(numbers1));
    print(numbers1); // 10 8.8 9 7 8 9 2 0 3 1 4 5 6

    std::pop_heap(begin(numbers1), end(numbers1));
    numbers1.pop_back();
    print(numbers1); // 9 8.8 9 7 8 6 2 0 3 1 4 5

    std::sort_heap(begin(numbers1), end(numbers1));
    print(numbers1); // 0 1 2 3 4 5 6 7 8 8.8 9 9

    return 0;
}