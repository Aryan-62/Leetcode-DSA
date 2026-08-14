#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;

        // Helper lambda to expand outward from a given center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if (currentLen > maxLen) {
                    start = left;
                    maxLen = currentLen;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < s.length(); i++) {
            expand(i, i);     // Odd-length palindromes (center at i)
            expand(i, i + 1); // Even-length palindromes (center between i and i+1)
        }

        return s.substr(start, maxLen);
    }
};