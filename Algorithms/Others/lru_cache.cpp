#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache
{
private:
    std::list<std::pair<int, int>> list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    int max;

public:
    LRUCache(int capacity)
    {
        cache.reserve(capacity);
        max = capacity;
    }

    int get(int key)
    {
        if (cache.count(key))
        {
            // change the list to have this key on the begin of the list since is
            // now the most recently used
            list.splice(list.begin(), list, cache[key]);
            return cache[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            list.splice(list.begin(), list, cache[key]);
            cache[key]->second = value;
            return;
        }
        if (max == cache.size())
        {
            // Remove the Least Recently Used which is on the back
            int tempKey = list.back().first;
            cache.erase(tempKey);
            list.pop_back();
        }
        // Add the new one to the front
        list.push_front({key, value});
        cache[key] = list.begin();
    }
};
int main()
{
    LRUCache *lRUCache = new LRUCache(4);
    lRUCache->put(1, 1);                        // cache is {1=1}
    lRUCache->put(2, 2);                        // cache is {1=1, 2=2}
    lRUCache->put(6, 6);                        // cache is {1=1, 2=2}
    lRUCache->put(7, 7);                        // cache is {1=1, 2=2}
    lRUCache->put(5, 5);                        // cache is {1=1, 2=2}
    std::cout << lRUCache->get(7) << std::endl; // return 1
    lRUCache->put(3, 3);                        // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    std::cout << lRUCache->get(2) << std::endl; // returns -1 (not found)
    lRUCache->put(4, 4);                        // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    std::cout << lRUCache->get(1) << std::endl; // return -1 (not found)
    std::cout << lRUCache->get(3) << std::endl; // return 3
    std::cout << lRUCache->get(4) << std::endl; // return 4
    return 0;
}