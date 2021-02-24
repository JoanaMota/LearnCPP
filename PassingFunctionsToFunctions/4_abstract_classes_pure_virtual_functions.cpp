#include <iostream>

// Abstract Class
class Animal
{
private:
public:
    Animal(){};
    ~Animal(){};
    virtual void run() = 0;
    virtual void speak() = 0;
};
// Derived Class but also an Abstract Class
class Dog : public Animal
{
private:
public:
    Dog(){};
    ~Dog(){};
    virtual void speak()
    {
        std::cout << "Woof" << std::endl;
    }
};
// Subclass
class Labrador : public Dog
{
public:
    Labrador()
    {
        std::cout << "New Labrador" << std::endl;
    };
    ~Labrador(){};
    void run()
    {
        std::cout << "Labrador Running" << std::endl;
    }
};

void test(Animal &a)
{
    a.run();
}

int main()
{
    // Animal animal; // You cant instantiate Animal
    // Dog dog; // You cant instantiate Dog
    Labrador lab;
    lab.speak();
    lab.run();

    // Animal animal[]; // You cant create an array of Animals because you cant call the Animal constructor
    Labrador labs[5];
    // But you can create an array for pointer to Animal
    Animal *animals[5];
    animals[0] = &lab;
    animals[0]->speak();
    animals[0]->run();

    test(lab);

    return 0;
}