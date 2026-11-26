#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalSurplus = 0;
        int currentTank = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int netGas = gas[i] - cost[i];
            totalSurplus += netGas;
            currentTank += netGas;

            // If the tank drops below 0, startStation cannot reach station i + 1
            if (currentTank < 0) {
                startStation = i + 1;
                currentTank = 0;
            }
        }

        return (totalSurplus >= 0) ? startStation : -1;
    }
};