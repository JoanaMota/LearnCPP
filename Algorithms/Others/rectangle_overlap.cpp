#include <iostream>
#include <vector>

bool isRectangleOverlap(std::vector<int> &rec1, std::vector<int> &rec2)
{
    // X2rec1 <= X1rec2
    // X2rec2 <= X1rec1
    // Y2rec1 <= Y1rec2
    // Y2rec2 <= Y1rec1
    if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
    {
        return false;
    }
    return true;
}

int main()
{
    std::vector<int> rec1 = {0, 0, 1, 1};
    std::vector<int> rec2 = {1, 1, 3, 3};
    std::cout << std::boolalpha << isRectangleOverlap(rec1, rec2) << std::endl;
    return 0;
}