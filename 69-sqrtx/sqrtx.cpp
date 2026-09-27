class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use division (mid <= x / mid) to prevent 32-bit integer overflow
            if (mid <= x / mid) {
                ans = mid;         // mid could be the answer, try larger
                left = mid + 1;
            } else {
                right = mid - 1;   // mid is too large, search left half
            }
        }

        return ans;
    }
};