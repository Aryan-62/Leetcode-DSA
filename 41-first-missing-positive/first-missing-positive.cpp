#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number in its correct 0-indexed position:
        // A value `x` should ideally be placed at index `x - 1`.
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first index where nums[i] != i + 1
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If all positions 1 through n are present, the answer is n + 1
        return n + 1;
    }
};