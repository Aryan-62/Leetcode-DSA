class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes.
        // Also, if the last digit is 0, the first digit must be 0 (only 0 itself satisfies this).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Reverse only half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even length digits: x == reversedHalf (e.g., 1221 -> x = 12, reversedHalf = 12)
        // For odd length digits: x == reversedHalf / 10 (e.g., 12321 -> x = 12, reversedHalf = 123)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};