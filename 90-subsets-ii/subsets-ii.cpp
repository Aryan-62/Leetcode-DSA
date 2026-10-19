#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int start, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Add current subset to results
        result.push_back(current);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sorting is crucial to handle duplicates
        std::sort(nums.begin(), nums.end());
        
        backtrack(0, nums, current, result);
        return result;
    }
};