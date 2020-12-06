#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> ages;

    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    ages["Mike"] = 70; // Overides Mikes' age

    std::cout << ages["Raj"] << std::endl;

    //This will print something that does no exist but it will add it to the map
    // Weird
    std::cout << ages["Sue"] << std::endl;
    // Before using map member it is better to find it in the map
    if (ages.find("Joana") != ages.end())
    {
        std::cout << "Found Joana" << std::endl;
    }
    else
    {
        std::cout << "Key Joana Not found" << std::endl;
    }

    // Print all menbers of map
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    // Another option to print all menbers of map
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    // Another ways of inserting members to map
    ages.insert(std::pair<std::string, int>("Peter", 100));
    ages.insert(std::make_pair("Elen", 100));
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    return 0;
}