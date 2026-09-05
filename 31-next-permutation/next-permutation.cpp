#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first decreasing element from the back
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. If a valid pivot was found, find the element just larger than nums[i]
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }

        // 3. Reverse the elements after index i
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};