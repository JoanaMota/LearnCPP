#include <iostream>
#include <map>
#include "colors.hpp"

// Use and object as map keys
// map < CObject, int>

class Person
{
private:
    std::string name;
    int age;

public:
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

    void print() const
    {
        std::cout << name << " : " << age << std::flush;
    }
    // Operator overload
    // method must be const
    // We need the operator overload because the map orders the elements by keys
    // so we need to define how the map should order by the key Person
    bool operator<(const Person &other) const
    {
        if (name == other.name)
        {
            return age < other.age;
        }
        else
        {
            return name < other.name;
        }
    }
};

int main()
{
    std::map<Person, int> people;
    people[Person("Mike", 40)] = 1;
    people[Person("Mike", 40)] = 2;
    // It can overite the value but not the existing key
    people[Person("Mike", 333)] = 3; // Therefore I'll update the value of this existing
                                     // key to have this new value but that the key itself
                                     // is not going to be changed it's not going to overwrite the existing key.
    people[Person("Raj", 20)] = 22;
    people[Person("Vicky", 30)] = 50;
    Person person1 = Person("Vicky", 30);
    Person person2 = person1; // Call copy constructor

    people.insert(std::make_pair(Person("Joana", 25), 2)); // Calls the copy constructor 2 times????

    for (std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
    {
        std::cout << it->second << " : " << std::flush;
        it->first.print();
        std::cout << std::endl;
    }

    return 0;
}
