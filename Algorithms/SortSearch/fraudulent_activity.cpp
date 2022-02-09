#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
#include <assert.h>

int getMedian(std::vector<int> &count, int d)
{
    int a{0};
    int b{0};

    // Iterate through count an sum the counters until we find the left and right for the median

    //d is even -> median = a + b
    if (d % 2 == 0)
    {
        int left = d / 2;
        int right = left + 1;
        int counter{0};
        for (int i = 0; i < 201; i++)
        {
            counter += count[i];
            if (counter >= left && a == 0)
            {
                a = i;
            }

            if (counter >= right)
            {
                b = i;
                break;
            }
        }
    }
    else //d is odd -> median = a + a
    {
        int left = d / 2 + 1;
        int counter{0};
        for (int i = 0; i < 201; i++)
        {
            counter += count[i];
            if (counter >= left)
            {
                a = i;
                break;
            }
        }
        b = a;
    }
    return a + b; // return the sum and this way we don't need to multiply by 2 afterwards
}

int activityNotifications(std::vector<int> &expenditure, int d)
{
    // Using counting sort https://www.programiz.com/dsa/counting-sort
    std::vector<int> count(201, 0);
    for (int i = 0; i < d; i++)
    {
        count[expenditure[i]]++;
    }
    int nrNotices{0}, n((int)expenditure.size());
    int startIt{0};
    for (int i = d; i < n; i++)
    {
        int doubleMedian = getMedian(count, d);
        if (expenditure[i] >= doubleMedian)
        {
            nrNotices++;
        }
        count[expenditure[i]]++;
        count[expenditure[startIt]]--;
        startIt++;
    }
    return nrNotices;
}

int main()
{
    std::vector<int> expenditure = {0, 82, 180, 55, 168, 41, 179, 59, 139, 71, 6, 12, 135, 139, 73, 157, 4, 74, 195, 60, 45, 28, 67, 136, 58, 55, 22, 60, 33, 84, 48, 185, 118, 29, 41, 86, 22, 172, 145, 114, 43, 103, 126, 130, 43, 152, 87, 199, 26, 34, 59, 24, 63, 79, 160, 73, 86, 134, 133, 71, 18, 182, 57, 89, 163, 98, 175, 137, 70, 73, 3, 113, 176, 130, 43, 19, 34, 83, 170, 12, 117, 30, 36, 132};
    std::cout << activityNotifications(expenditure, 10) << std::endl;
    return 0;
}