#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, int target, std::vector<int>& candidates, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case 1: Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Because the array is sorted, if candidates[i] exceeds the target,
            // no subsequent element can fit either.
            if (candidates[i] > target) {
                break;
            }

            // Choose
            current.push_back(candidates[i]);

            // Explore: pass 'i' (not 'i + 1') because we can reuse the same element
            backtrack(i, target - candidates[i], candidates, current, result);

            // Un-choose (backtrack)
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Sorting allows early stopping (pruning) when candidates[i] > target
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);

        return result;
    }
};