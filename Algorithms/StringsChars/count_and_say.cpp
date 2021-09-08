#include <iostream>

std::string countAndSayBad(int n)
{
    std::cout << n << std::endl;
    if (n == 1)
    {
        return "1";
    }

    std::string output = countAndSayBad(n - 1);
    std::cout << "output: " << output << std::endl;

    if (output.size() == 1)
    {
        return "11";
    }
    std::cout << "before for" << std::endl;
    int counter{1};
    std::string output2{""};
    int i;
    for (i = 0; i < output.size() - 1; i++)
    {
        std::cout << "i: " << i << std::endl;
        if (output[i] == output[i + 1])
        {
            counter++;
        }
        else
        {
            output2 = output2 + std::to_string(counter) + output[i];
            std::cout << "output2: " << output2 << std::endl;
            counter = 1;
        }
    }
    output2 = output2 + std::to_string(counter) + output[i];
    std::cout << "output2 end: " << output2 << std::endl;

    return output2;
}

std::string countAndSay(int n)
{

    std::string str1 = "1";
    std::string str2 = "";
    if (n == 1)
        return str1;
    for (int i = 2; i <= n; ++i)
    {
        int count = 1;
        int s1 = str1.size();
        int j = 0;
        while (j < s1)
        {
            if (str1[j] == str1[j + 1])
            {
                count++;
                j++;
            }
            else
            {
                str2 += std::to_string(count);
                str2 += str1[j];
                j++;
                count = 1;
            }
        }
        str1 = str2;
        str2 = "";
    }

    return str1;
}

int main()
{
    std::cout << countAndSay(4) << std::endl;
    return 0;
}