#include <iostream>
#include <vector>

void print(int v)
{
    std::cout << v << std::endl;
}

const int16_t sizeTest = 90;
struct TestInput
{
    std::vector<int16_t> data1;
    std::vector<int16_t> data2;
    std::vector<int16_t> data3;
};

struct TestOutput
{
    int16_t data1[sizeTest];
    int16_t data2[sizeTest];
    int16_t data3[sizeTest];
};

#pragma pack(1)
struct MainTest
{
    uint8_t someU8;
    TestOutput output;
};
#pragma pack() // keep the 51 bytes instead of 52 optimized by the compiler

class CTT
{
private:
    TestInput input;

public:
    void init();
    void execute(MainTest &test);
};

void CTT::init()
{
    for (int joana1 = 0; joana1 < sizeTest; joana1++)
    {
        input.data1.push_back(joana1);
        input.data2.push_back(joana1);
        input.data3.push_back(joana1);
    }

    std::cout << "Size input.data1: " << input.data1.size() << std::endl;
    std::cout << "Size input.data2: " << input.data2.size() << std::endl;
    std::cout << "Size input.data3: " << input.data3.size() << std::endl;
    input.data1.resize(sizeTest);
    input.data2.resize(sizeTest);
    input.data3.resize(sizeTest);
}
void CTT::execute(MainTest &test)
{
    for (int joana2 = 0; joana2 < sizeTest; joana2++)
    {
        test.output.data1[joana2] = input.data1[joana2];
        test.output.data2[joana2] = input.data2[joana2];
        test.output.data3[joana2] = input.data3[joana2];
    }
}

int main()
{
    CTT ctt;
    ctt.init();
    std::cout << "Size MainTest: " << sizeof(MainTest) << std::endl;
    MainTest test;
    ctt.execute(test);
    std::cout << "Size of test.output.data1: " << sizeof(test.output.data1) << std::endl;
    std::cout << "Size of test.output.data2: " << sizeof(test.output.data2) << std::endl;
    std::cout << "Size of test.output.data3: " << sizeof(test.output.data3) << std::endl;

    return 0;
}