#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        // Traverse backwards from the least significant digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry propagates further; return immediately
            }
            // If the digit is 9, it becomes 0 and carry continues
            digits[i] = 0;
        }
        
        // If all digits were 9 (e.g., [9, 9, 9] -> [0, 0, 0]),
        // prepend a 1 to make it [1, 0, 0, 0]
        digits.insert(digits.begin(), 1);
        return digits;
    }
};