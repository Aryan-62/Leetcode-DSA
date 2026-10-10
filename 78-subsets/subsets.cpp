#include <vector>

class Solution {
public:
    void backtrack(int index, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: processed all elements
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Choice 1: Include nums[index]
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, result);

        // Backtrack: Remove nums[index] to try the other choice
        current.pop_back();

        // Choice 2: Exclude nums[index]
        backtrack(index + 1, nums, current, result);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};