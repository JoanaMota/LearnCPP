#include <iostream>
#include <vector>

std::string reverseWords(std::string s)
{
    std::vector<std::string> sentence;
    std::string word{""};
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (!word.empty())
            {
                sentence.push_back(word);
                word = "";
            }
        }
        else
        {
            word += s[i];
        }
    }
    if (!word.empty())
    {
        sentence.push_back(word);
    }

    std::string output{""};
    for (int i = sentence.size() - 1; i >= 0; i--)
    {
        output += sentence[i];
        if (i != 0)
        {
            output += " ";
        }
    }

    return output;
}

int main()
{
    std::cout << reverseWords(" a good   example ") << std::endl;
    std::string word{""};
    std::cout << std::boolalpha << word.empty() << std::endl;
    word += "jo";
    std::cout << std::boolalpha << word.empty() << std::endl;
    word = "";
    std::cout << std::boolalpha << word.empty() << std::endl;
    return 0;
}