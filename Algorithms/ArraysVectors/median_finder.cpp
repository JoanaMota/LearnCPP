#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>

class MedianFinderVector
{
private:
    std::vector<int> m_nums;
    int m_size;

public:
    MedianFinderVector()
    {
    }

    void addNum(int num)
    {
        m_nums.push_back(num);
        std::sort(m_nums.begin(), m_nums.end());
        m_size = m_nums.size();
    }

    double findMedian()
    {
        double median;
        if (0 == m_size % 2)
        {
            int middle = m_size / 2;
            median = (double)((m_nums[middle - 1] + m_nums[middle]) / 2.0);
        }
        else
        {
            median = (double)m_nums[std::floor(m_size / 2.0)];
        }
        return median;
    }
};

class MedianFinderDeque
{
private:
    std::deque<int> m_nums;
    int m_size;

public:
    MedianFinderDeque()
    {
    }

    void addNum(int num)
    {
        if (0 == m_size)
        {
            m_nums.push_back(num);
        }
        else
        {
            auto it = std::upper_bound(m_nums.begin(), m_nums.end(), num);
            m_nums.insert(it, num);
        }
        m_size = m_nums.size();
    }

    double findMedian()
    {
        double median;
        if (0 == m_size % 2)
        {
            int middle = m_size / 2;
            median = (double)((m_nums[middle - 1] + m_nums[middle]) / 2.0);
        }
        else
        {
            median = (double)m_nums[std::floor(m_size / 2.0)];
        }
        return median;
    }
};

class MedianFinder
{
public:
    std::priority_queue<double> maxHeap;                                         // smaller values
    std::priority_queue<double, std::vector<double>, std::greater<int>> minHeap; // greater values
    double median;
    MedianFinder()
    {
        median = 0;
    }
    void addNum(int num)
    {
        if (maxHeap.size() == 0 && minHeap.size() == 0)
        {
            median = num;
        }
        if (maxHeap.size() == minHeap.size())
        {
            if (median < num)
            {
                minHeap.push(num);
                median = minHeap.top();
            }
            else
            {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if (maxHeap.size() > minHeap.size())
        {
            if (median > num)
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else
        {
            if (median < num)
            {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
    double findMedian()
    {
        return median;
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(6);
    std::cout << obj->findMedian() << std::endl;
    obj->addNum(10);
    std::cout << obj->findMedian() << std::endl;
    obj->addNum(2);
    std::cout << obj->findMedian() << std::endl;
    obj->addNum(6);
    std::cout << obj->findMedian() << std::endl;
    obj->addNum(5);
    std::cout << obj->findMedian() << std::endl;
    return 0;
}