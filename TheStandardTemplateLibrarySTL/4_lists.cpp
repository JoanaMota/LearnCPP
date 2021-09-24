#include <iostream>
#include <list>

void print(std::list<int> &f_list)
{
    for (int element : f_list)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    print(numbers);

    std::list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    std::cout << "Element: " << *it << std::endl;
    print(numbers);

    std::list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt);
    std::cout << "Next Element: " << *eraseIt << std::endl;
    print(numbers);

    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end();)
    {
        if (*it == 2)
        {
            numbers.insert(it, 5555);
        }
        if (*it == 1)
        {
            // The erase will invalidate te iterator(it) so it will be pointting to somewhere else.
            // Therefore we should reasigne it to point to the next iterator on the list
            it = numbers.erase(it);
        }
        else
        {
            // We have to increment the iterator here because the other condition incremetes the iterator
            // and therefore the iterator would be incremented twice in the previous condition
            it++;
        }
    }
    print(numbers);
    numbers.sort();
    print(numbers);

    return 0;
}