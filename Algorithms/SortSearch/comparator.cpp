#include <iostream>

struct Player
{
    int score;
    std::string name;
};

class Checker
{
public:
    // complete this method
    static int comparator(Player a, Player b)
    {
        int output{0};
        if (a.score == b.score)
        {
            int minSize{std::min((int)a.name.size(), (int)b.name.size())};
            int it{0};
            while (minSize != it)
            {
                if (a.name[it] == b.name[it])
                {
                    it++;
                    continue;
                }
                else if (a.name[it] < b.name[it])
                {
                    output = 1;
                    break;
                }
                else
                {
                    output = -1;
                    break;
                }
            }
            if (0 == output)
            {
                if (a.name.size() < b.name.size())
                {
                    output = 1;
                }
                else
                {
                    output = -1;
                }
            }
        }
        else if (a.score < b.score)
        {
            output = -1;
        }
        else
        {
            output = 1;
        }
        return output;
    }
};
