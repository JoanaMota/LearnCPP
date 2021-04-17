#include <iostream>
#include <vector>

int main()
{
    // -----C++98-----
    // Integer
    int value = 5;
    // String
    std::string text = "Hello";
    // Array
    int values[] = {1, 5, 8, 8};

    // Class
    class C
    {
    public:
        std::string text;
        int id;
    };
    C c1 = {"Hello", 5};
    std::cout << c1.text << " " << c1.id << std::endl;

    // Struct
    struct S
    {
        std::string text;
        int id;
    };
    S s1 = {"Joana", 4};
    std::cout << s1.text << " " << s1.id << std::endl;
    struct SS
    {
        std::string text;
        int id;
    } ss1 = {"Hello", 5}, ss2 = {"Hi", 9};
    std::cout << ss1.text << " " << ss1.id << std::endl;
    std::cout << ss2.text << " " << ss2.id << std::endl;

    // Vector
    std::vector<std::string> strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");

    // -----C++11-----
    // Integer
    int value1{5};
    int value2{};
    std::cout << "value2: " << value2 << std::endl;
    // String
    std::string text1{"Hello"};
    // Array
    int numbers[]{1, 2, 4};
    int numbers1[5]{}; // Initialize all to zero
    std::cout << "numbers1[2]: " << numbers1[2] << std::endl;
    int *pInts = new int[3]{1, 2, 4};
    delete pInts;

    // Pointers
    int *pSomething{&value1};
    std::cout << "pSomething: " << *pSomething << std::endl;
    int *pSomething1{};                                       // equivalent to int *pSomething = nullptr
    std::cout << "pSomething1: " << pSomething1 << std::endl; // address will be 0

    // Struct
    struct S11
    {
        std::string text;
        int id;
    } s11{"Joana", 4};

    // Vectors
    // C++ uses initialization list to beable to initialize vectors like this
    std::vector<std::string> strings1{"one", "two", "three"};
    std::cout << strings1[1] << std::endl;

    return 0;
}