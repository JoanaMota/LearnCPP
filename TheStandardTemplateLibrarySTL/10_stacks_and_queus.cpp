#include <iostream>
#include <stack>
#include <queue>

class CTest
{
private:
    std::string m_name;

public:
    CTest(std::string f_name) : m_name(f_name)
    {
        std::cout << "Object " << m_name << " created" << std::endl;
    }
    ~CTest()
    {
        std::cout << "Object " << m_name << " destroyed" << std::endl;
    }
    void print(void)
    {
        std::cout << m_name << std::endl;
    }
};

int main()
{
    std::cout << "------STACK------" << std::endl;
    // LIFO
    std::stack<CTest> testStack;

    testStack.push(CTest("Mike")); // This Mike local copy is created and destroyed here
                                   // and copied to the stack with (shallow copy, the default copy Constructor)
    testStack.push(CTest("Joana"));
    testStack.push(CTest("Joao"));
    testStack.push(CTest("Miguel"));
    testStack.push(CTest("Sara"));
    testStack.push(CTest("John"));
    testStack.push(CTest("Sue"));
    std::cout << "Stack size: " << testStack.size() << std::endl;
    std::cout << std::endl;

    /* This is invaid code! Object is destroyed.
    // Create a reference to an object of the stack
    //   This can be dangerous because this object is destroyed
    //   with a pop per instance the reference could probably be 
    //   pointing to somewhere else 
    CTest &test1 = testStack.top(); // Sue
    testStack.pop();
    test1.print(); // Reference refers to destroyed object
    */

    testStack.pop(); // Destroys Sue object
    std::cout << "Stack size: " << testStack.size() << std::endl;
    CTest test1 = testStack.top(); // Use a shallow copy to copy John obj to test
                                   // This will be destroyed at the end of the program
    test1.print();
    std::cout << "Stack size: " << testStack.size() << std::endl;

    std::cout << std::endl;
    std::cout << "--Iterate through stack--" << std::endl;
    while (testStack.size() > 0)
    {
        CTest &test = testStack.top();
        test.print();
        testStack.pop();
    }
    std::cout << "--END Iterate through stack--" << std::endl;

    std::cout << "------QUEUE------" << std::endl;
    // FIFO
    std::queue<CTest> testQueue;

    testQueue.push(CTest("Mike")); // This Mike local copy is created and destroyed here
                                   // and copied to the queue with (shallow copy, the default copy Constructor)
    testQueue.push(CTest("Joana"));
    testQueue.push(CTest("Joao"));
    testQueue.push(CTest("Miguel"));
    testQueue.push(CTest("Sara"));
    testQueue.push(CTest("John"));
    testQueue.push(CTest("Sue"));
    std::cout << "Stack size: " << testQueue.size() << std::endl;

    std::cout << "Front element of the queue: ";
    testQueue.front().print();
    std::cout << "Back element of the queue: ";
    testQueue.back().print();
    std::cout << std::endl;

    testQueue.pop(); // Destroyes Mike object
    std::cout << "Stack size: " << testQueue.size() << std::endl;
    CTest test2 = testQueue.front(); // First element of the queue
                                     // Use a shallow copy to copy Joana obj to test
                                     // This will be destroyed at the end of the program
    test2.print();
    std::cout << "Stack size: " << testQueue.size() << std::endl;

    std::cout << std::endl;
    std::cout << "--Iterate through queue--" << std::endl;
    while (testQueue.size() > 0)
    {
        CTest &test = testQueue.front();
        test.print();
        testQueue.pop();
    }
    std::cout << "--END Iterate through queue--" << std::endl;

    // DEQUE
    std::cout << "------QUEUE------" << std::endl;
    // Declare a deque
    std::deque<int> dq;

    // Insert element in the front
    dq.push_front(10);
    dq.push_front(5);
    dq.push_front(3);

    // Delete elements from the the front
    dq.pop_front();
    dq.pop_front();

    // Insert elements in the back
    dq.push_back(1);
    dq.push_back(50);
    dq.push_back(2);

    // Delete elements from the the back
    dq.pop_back();
    dq.pop_back();

    std::cout << "Elements in deque are: " << std::endl;
    for (int val : dq)
        std::cout << val << " ";

    std::deque<int>::iterator it = dq.begin();
    ++it;
    it = dq.insert(it, 105);
    std::cout << "Elements in deque are: " << std::endl;
    for (int val : dq)
        std::cout << val << " ";

    std::cout << std::endl;
    // Print the element stored in deque and remove them
    while (!dq.empty())
    {
        std::cout << dq.back() << " ";
        dq.pop_back();
    }

    std::cout << std::endl;
    return 0;
}