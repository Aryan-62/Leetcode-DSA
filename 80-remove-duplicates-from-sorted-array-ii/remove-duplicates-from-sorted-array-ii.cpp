#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int k = 2; // Start writing from index 2
        for (int i = 2; i < nums.size(); ++i) {
            // Compare the current number with the one written 2 spots back
            if (nums[i] > nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};