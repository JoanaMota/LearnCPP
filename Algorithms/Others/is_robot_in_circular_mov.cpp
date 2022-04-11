#include <iostream>

enum Orientation
{
    N = 0,
    E = 1,
    S = 2,
    W = 3,
};

// path = G(go 1 unit), L(turn left), R(turn right)
bool isCicular(std::string path)
{
    // 0 0 we start pointing north;
    int x{0}, y{0};
    Orientation ori = Orientation::N;

    for (char cm : path)
    {
        if (cm == 'G')
        {
            switch (ori)
            {
            case Orientation::N:
                y++;
                break;
            case Orientation::S:
                y--;
                break;
            case Orientation::E:
                x++;
                break;
            case Orientation::W:
                x--;
                break;
            default:
                break;
            }
        }
        else if (cm == 'L')
        {
            ori = (Orientation)((4 + (int)ori - 1) % 4);
        }
        else if (cm == 'R')
        {
            ori = (Orientation)(((int)ori + 1) % 4);
        }
    }
    if (x == 0 && y == 0)
    {
        return true;
    }
    return false;
}

enum ECardinal : uint8_t
{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
};
// path G - go in front, L - turn left, R - turn right
bool isCicular2(std::string path)
{
    int x{0}, y{0};
    ECardinal orientation = ECardinal::NORTH;

    bool firstStep{false};

    for (char command : path)
    {
        switch (command)
        {
        case 'G':
            firstStep = true;
            if (orientation == ECardinal::NORTH)
            {
                y++;
            }
            else if (orientation == ECardinal::EAST)
            {
                x++;
            }
            else if (orientation == ECardinal::SOUTH)
            {
                y--;
            }
            else if (orientation == ECardinal::WEST)
            {
                x--;
            }
            break;
        case 'L':
            if (orientation == ECardinal::NORTH)
            {
                orientation = ECardinal::WEST;
            }
            else
            {
                orientation = (ECardinal)((int)orientation - 1);
            }
            break;
        case 'R':
            if (orientation == ECardinal::WEST)
            {
                orientation = ECardinal::NORTH;
            }
            else
            {
                orientation = (ECardinal)((int)orientation + 1);
            }

            break;

        default:
            break;
        }

        if (firstStep && 0 == x && 0 == y)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::cout << std::boolalpha << isCicular2("GLGLGGLGRG") << std::endl;
    return 0;
}