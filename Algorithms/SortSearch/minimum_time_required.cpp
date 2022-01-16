#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// long minTime(std::vector<long> machines, long goal)
// {
//     std::unordered_map<long, int> machinesDays;
//     for (long machine : machines)
//     {
//         machinesDays[machine]++;
//     }

//     long nrDays{0};
//     long nrItems{0};
//     while (nrItems < goal)
//     {
//         auto it = machinesDays.find(nrDays);
//         if (it != machinesDays.end())
//         {
//             nrItems += machinesDays[nrDays];
//             machinesDays[nrDays + nrDays] = machinesDays[nrDays];
//             machinesDays.erase(it);
//         }
//         nrDays++;
//     }
//     return nrDays;
// }
long minTime(std::vector<long> machines, long goal)
{
    int nrMachines = machines.size();
    std::sort(machines.begin(), machines.end());
    long maxNrDays = (long)((goal * machines[nrMachines - 1]) / nrMachines);
    long minNrDays = (long)((goal * machines[0]) / nrMachines);

    int nrItems{0};
    long middle;
    while (maxNrDays > minNrDays)
    {
        middle = (int)((maxNrDays + minNrDays) / 2);
        nrItems = 0;
        for (int i = 0; i < machines.size(); i++)
        {
            nrItems += (long)(middle / machines[i]);
        }
        if (nrItems < goal)
        {
            minNrDays = middle + 1;
        }
        else
        {
            maxNrDays = middle;
        }
    }
    return maxNrDays;
}

int main()
{
    std::vector<long> machines = {1, 3, 4};
    std::cout << minTime(machines, 10) << std::endl;
    return 0;
}