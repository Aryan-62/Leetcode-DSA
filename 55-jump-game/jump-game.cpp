#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the furthest reachable index,
            // we cannot move forward.
            if (i > maxReach) {
                return false;
            }

            // Update the furthest reachable index
            maxReach = std::max(maxReach, i + nums[i]);

            // If we can already reach or pass the last index, return true early
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};