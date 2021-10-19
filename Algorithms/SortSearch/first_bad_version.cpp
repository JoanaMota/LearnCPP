#include <iostream>

bool isBadVersion(int version)
{
    if (4 == version)
        return true;
    else if (5 == version)
        return true;
    else if (6 == version)
        return true;
    else if (7 == version)
        return true;
    else
        return false;
}

int firstBadVersion(int n) // O(n)
{
    int i;
    for (i = n; i > 0; --i)
    {
        if (!isBadVersion(i))
            break;
    }
    return i + 1;
}

int firstBadVersionFaster(int n) // O(log n)
{
    int lower = 1;
    int upper = n;

    while (lower < upper)
    {
        int mid = lower + (upper - lower) / 2;
        if (isBadVersion(mid) == false)
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid;
        }
    }
    return lower;
}

int main()
{
    std::cout << firstBadVersionFaster(5) << std::endl;
    return 0;
}