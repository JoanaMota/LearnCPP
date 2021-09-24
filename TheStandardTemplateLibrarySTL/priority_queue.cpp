#include <iostream>
#include <queue>

template <typename T>
void print(T f_queue) // pass by value so the print uses a copy
{
    while (!f_queue.empty())
    {
        std::cout << f_queue.top() << " ";
        f_queue.pop();
    }
    std::cout << std::endl;
}

int main()
{
    // Max Heap
    std::cout << "Max Heap!" << std::endl;
    std::priority_queue<int> pqueue;
    pqueue.push(10);
    pqueue.push(30);
    pqueue.push(20);
    pqueue.push(5);
    pqueue.push(1);
    print(pqueue);
    std::cout << "Top: " << pqueue.top() << std::endl;
    std::cout << "Size: " << pqueue.size() << std::endl;
    pqueue.pop();
    std::cout << "Size after pop: " << pqueue.size() << std::endl;
    print(pqueue);

    // Min Heap
    std::cout << "Min Heap!" << std::endl;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqueueMin;
    pqueueMin.push(10);
    pqueueMin.push(30);
    pqueueMin.push(20);
    pqueueMin.push(5);
    pqueueMin.push(1);
    print(pqueueMin);
    std::cout << "Top: " << pqueueMin.top() << std::endl;
    std::cout << "Size: " << pqueueMin.size() << std::endl;
    pqueueMin.pop();
    std::cout << "Size after pop: " << pqueueMin.size() << std::endl;
    print(pqueueMin);
    return 0;
}