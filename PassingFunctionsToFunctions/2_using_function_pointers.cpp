#include <iostream>
#include <algorithm>
#include <vector>

bool match(const std::string f_text)
{
    return f_text.size() == 3;
}
// Our implementation of count_if just to show an example how to pass a function pointer as a function argument
int countString(std::vector<std::string> &texts, bool (*pMatch)(std::string))
{
    int count = 0;
    for (int i = 0; i < texts.size(); i++)
    {
        if (pMatch(texts[i]))
            count++;
    }
    return count;
}

int main()
{
    std::vector<std::string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("one");
    texts.push_back("four");
    texts.push_back("one");
    texts.push_back("five");
    texts.push_back("six");

    std::cout << match("one") << std::endl;

    std::cout << "Counter count_if: " << std::count_if(texts.begin(), texts.end(), match) << std::endl; // pass match as a function pointer

    std::cout << "Our Counter: " << countString(texts, match) << std::endl; // pass match as a function pointer

    return 0;
}