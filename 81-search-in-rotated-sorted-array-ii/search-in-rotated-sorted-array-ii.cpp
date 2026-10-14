#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle the duplicate boundary case
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Case 1: Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // target lies in the left half
                } else {
                    low = mid + 1;  // target lies in the right half
                }
            }
            // Case 2: Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // target lies in the right half
                } else {
                    high = mid - 1; // target lies in the left half
                }
            }
        }

        return false;
    }
};