#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // Loop until nums.size() - 1 because we don't need to jump once we are at the last index
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Track the farthest point reachable from current range
            farthest = std::max(farthest, i + nums[i]);

            // When we reach the end of our current jump window
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }

        return jumps;
    }
};