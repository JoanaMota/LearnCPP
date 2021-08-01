// C++ code to demonstrate tuple, get() and make_pair()
#include <iostream>
#include <tuple> // for tuple

void print(std::tuple<char, int, float> f_data)
{
    std::cout << "The values of tuple are : ";
    std::cout << std::get<0>(f_data) << " " << std::get<1>(f_data);
    std::cout << " " << std::get<2>(f_data) << std::endl;
}

int main()
{
    // Declaring tuple
    std::tuple<char, int, float> data1;

    // Assigning values to tuple
    data1 = std::make_tuple('a', 10, 15.5);
    print(data1);

    // Use of std::get() to change values of tuple
    std::get<0>(data1) = 'b';
    std::get<2>(data1) = 20.5;
    print(data1);

    std::cout << "The size of tuple is : ";
    std::cout << std::tuple_size<decltype(data1)>::value << std::endl;

    // Swap
    std::tuple<char, int, float> data2('c', 50, 5.5);
    std::cout << "Data2" << std::endl;
    print(data2);
    data1.swap(data2);
    std::cout << "Data1" << std::endl;
    print(data1);
    std::cout << "Data2" << std::endl;
    print(data2);

    // Tie
    char c_val;
    int i_val;
    float f_val;

    std::tie(c_val, i_val, f_val) = data1;
    std::cout << "The unpacked tuple values (without ignore) are : ";
    std::cout << c_val << " " << i_val << " " << f_val;
    std::cout << std::endl;

    std::tie(c_val, std::ignore, f_val) = data1;
    std::cout << "The unpacked tuple values (without ignore) are : ";
    std::cout << c_val << " " << f_val;
    std::cout << std::endl;

    // tuple_cat
    auto data3 = std::tuple_cat(data1, data2);
    std::cout << "The new tuple elements in order are : ";
    std::cout << std::get<0>(data3) << " " << std::get<1>(data3) << " ";
    std::cout << std::get<2>(data3) << " " << std::get<3>(data3) << " ";
    std::cout << std::get<4>(data3) << " " << std::get<5>(data3) << std::endl;
    return 0;
}
