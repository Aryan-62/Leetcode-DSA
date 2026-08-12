#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Map to store the last seen index + 1 of each character
        // Size 256 covers all standard ASCII characters
        std::vector<int> charMap(256, 0); 
        
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            // If the character was seen within the current window, move 'left'
            if (charMap[s[right]] > left) {
                left = charMap[s[right]];
            }

            // Store the 1-based index (index + 1) to distinguish from default 0
            charMap[s[right]] = right + 1;

            // Update maximum length
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};