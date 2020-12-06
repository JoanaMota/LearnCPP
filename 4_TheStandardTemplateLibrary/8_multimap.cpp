#include <iostream>
#include <map>
#include "colors.hpp"
int main()
{
    std::multimap<int, std::string> lookup;
    lookup.insert(std::make_pair(25, "Joana"));
    lookup.insert(std::make_pair(255, "Bob"));
    lookup.insert(std::make_pair(10, "Joao"));
    lookup.insert(std::make_pair(10, "Miguel"));
    lookup.insert(std::make_pair(2, "Sara"));

    for (std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    for (std::multimap<int, std::string>::iterator it = lookup.find(10); it != lookup.end(); it++)
    {
        std::cout << KYEL << it->first << ": " << it->second << RST << std::endl;
    }

    std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> iterators = lookup.equal_range(25);
    for (std::multimap<int, std::string>::iterator it = iterators.first; it != iterators.second; it++)
    {
        std::cout << KBLU << it->first << ": " << it->second << RST << std::endl;
    }

    auto iterators2 = lookup.equal_range(25);
    for (std::multimap<int, std::string>::iterator it = iterators2.first; it != iterators2.second; it++)
    {
        std::cout << KMAG << it->first << ": " << it->second << RST << std::endl;
    }

    return 0;
}