#include <iostream>
#include <map>
#include "colors.hpp"

// Use and object as map values
// map < int, CObject>

class Person
{
private:
    std::string name;
    int age;

    // Default Constructor
    // To initialize a map we need to have a default constructor
    Person() : name(""), age(0)
    {
        std::cout << KYEL << "Calling Default Constructor" << RST << std::endl;
    }
    // Copy Constructor
    Person(const Person &other)
    {
        std::cout << KBLU << "Calling Copy Constructor" << RST << std::endl;
        name = other.name;
        age = other.age;
    }
    // Constructor with input arguments
    Person(std::string f_name, int f_age) : name(f_name), age(f_age)
    {
        std::cout << KGRN << "Constructing Person object" << RST << std::endl;
    }
    // Destructor
    ~Person() {}

    void print()
    {
        std::cout << name << " : " << age << std::endl;
    }
};

int main()
{
    std::map<int, Person> people;
    people[50] = Person("Mike", 40);
    people[22] = Person("Raj", 20);
    people[1] = Person("Vicky", 30);
    Person person1 = Person("Vicky", 30);
    Person person2 = person1; // Call copy constructor

    people.insert(std::make_pair(2, Person("Joana", 25))); // Calls the copy constructor 2 times????

    for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {
        std::cout << it->first << " : " << std::flush;
        it->second.print();
    }

    return 0;
}
