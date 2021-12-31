#include <iostream>
#include <unordered_set>

class RandomizedSet
{
private:
    std::unordered_set<int> randSet;

public:
    RandomizedSet() {}
    ~RandomizedSet() {}
    bool insert(int val)
    {
        int prevSize = randSet.size();
        randSet.insert(val);
        return randSet.size() > prevSize;
    }
    bool remove(int val)
    {
        int prevSize = randSet.size();
        randSet.erase(val);
        return randSet.size() < prevSize;
    }
    int getRandom()
    {
        int var = std::rand() % randSet.size();
        std::unordered_set<int>::iterator it = randSet.begin();
        for (int i = 0; i < var; i++)
        {
            it++;
        }
        return *it;
    }
};

int main()
{
    RandomizedSet rand;
    std::cout << std::boolalpha << rand.insert(1) << std::endl;
    std::cout << std::boolalpha << rand.remove(2) << std::endl;
    std::cout << std::boolalpha << rand.insert(2) << std::endl;
    std::cout << std::boolalpha << rand.getRandom() << std::endl;
    std::cout << std::boolalpha << rand.remove(1) << std::endl;
    std::cout << std::boolalpha << rand.insert(2) << std::endl;
    std::cout << std::boolalpha << rand.getRandom() << std::endl;
    return 0;
}