#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, int target, std::vector<int>& candidates, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Prune search: since candidates is sorted, subsequent elements will also exceed target
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicate elements at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            // i + 1 ensures each element is used at most once
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back(); // backtrack
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        std::sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, current, result);

        return result;
    }
};