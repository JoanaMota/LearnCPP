#include <iostream>

template <class T, class S>
auto func(T input1, S input2)->decltype(input1 + input2)
{
    return input1 + input2;
}

int get()
{
    return 999;
}

auto test() -> decltype(get())
{
    return get();
}

int main()
{
    auto value = 7;
    auto text = "Hello World";
    std::cout << value << std::endl;
    std::cout << text << std::endl;
    std::cout << func(1, 5) << std::endl;
    std::cout << test() << std::endl;

    return 0;
}

// This is particularly useful when you've got to declare a really long sort of type declarations in situations where C++ is somehow able to figure it out.