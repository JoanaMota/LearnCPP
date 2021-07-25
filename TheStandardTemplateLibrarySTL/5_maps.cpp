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

    // Print all members of map
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    // Another option to print all members of map
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    // Insertion
    // Another ways of inserting members to map
    ages.insert({"Sue", 55});
    ages.insert(std::pair<std::string, int>("Peter", 100));
    ages.insert(std::make_pair("Elen", 100));
    std::cout << "---" << std::endl;
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    // Deletion
    ages.erase("Sue"); // erase by key

    auto it = ages.find("Peter");
    ages.erase(it); // erase by iterator

    std::cout << "---" << std::endl;
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    auto it1 = ages.find("Mike");
    auto it2 = ages.find("Vicky");
    ages.erase(it1, it2); // erase from it1 to it2 not including it2

    std::cout << "---" << std::endl;
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    return 0;
}