#include <vector>

class Solution {
public:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if combination has k elements, save it
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization (pruning):
        // Only loop up to (n - (k - current.size()) + 1) because
        // beyond that, there aren't enough remaining numbers to reach size k.
        for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
            current.push_back(i);                      // 1. Choose
            backtrack(i + 1, n, k, current, result);  // 2. Explore
            current.pop_back();                       // 3. Unchoose (backtrack)
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};