#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();
        int prev2 = 1; // ways to decode s[0...i-2]
        int prev1 = 1; // ways to decode s[0...i-1]

        for (int i = 1; i < n; ++i) {
            int current = 0;

            // Check single digit (s[i])
            if (s[i] != '0') {
                current += prev1;
            }

            // Check two digits (s[i-1] and s[i])
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            // Move forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};