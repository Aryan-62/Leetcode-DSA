#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int totalProfit = 0;
        
        for (size_t i = 1; i < prices.size(); ++i) {
            // Whenever today's price is higher than yesterday's, capture the gain
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        
        return totalProfit;
    }
};