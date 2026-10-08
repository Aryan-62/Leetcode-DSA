#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;       // Pointer to the last valid element in nums1
        int j = n - 1;       // Pointer to the last element in nums2
        int k = m + n - 1;   // Pointer to the write position at the end of nums1

        // Compare elements from the back and place the larger one at index k
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has remaining elements, copy them over.
        // (If nums1 has remaining elements, they are already in their correct places)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};