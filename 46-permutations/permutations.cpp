#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base case: if start index reaches the end, we have a complete permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // Swap current element with the element at index i
            std::swap(nums[start], nums[i]);

            // Recursively generate permutations for the remaining subarray
            backtrack(start + 1, nums, result);

            // Backtrack: undo the swap to restore the array state
            std::swap(nums[start], nums[i]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};