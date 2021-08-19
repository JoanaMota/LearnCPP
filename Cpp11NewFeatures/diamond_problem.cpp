#include <iostream>
using namespace std;
class Person
{
public:
    Person(int x) { cout << "Person(int)" << endl; }
    Person() { cout << "Person Default Constructor" << endl; }
    void hello() { cout << "Hello from Person" << endl; }
    ~Person() { cout << "Person Destructor" << endl; }
};

class Faculty : virtual public Person
{
public:
    Faculty(int x) : Person(x)
    {
        cout << "Faculty(int)" << endl;
    }
    void print() { cout << "Hello from Faculty" << endl; }
    ~Faculty() { cout << "Faculty Destructor" << endl; }
};

class Student : virtual public Person
{
public:
    Student(int x) : Person(x)
    {
        cout << "Student(int)" << endl;
    }
    void print() { cout << "Hello from Student" << endl; }
    ~Student() { cout << "Student Destructor" << endl; }
};

class TA : public Faculty, public Student
{
public:
    TA(int x) : Student(x), Faculty(x), Person(x)
    {
        cout << "TA(int)" << endl;
    }
    ~TA() { cout << "TA Destructor" << endl; }
};

class A
{
    int x;

public:
    void setX(int i) { x = i; }
    void print() { cout << x << endl; }
};

class B : virtual public A
{
public:
    B() { setX(10); }
};

class C : virtual public A
{
public:
    C() { setX(20); }
};

class D : public B, public C
{
};

int main()
{
    TA ta1(30);
    ta1.hello();
    ta1.Student::print();
    D d;
    d.print();
    return 0;
}
