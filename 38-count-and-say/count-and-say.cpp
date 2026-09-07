#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string current = "1";

        // Generate each term from 2 to n iteratively
        for (int step = 2; step <= n; ++step) {
            std::string next_term = "";
            int len = current.length();

            for (int i = 0; i < len; ) {
                int count = 0;
                char digit = current[i];

                // Count consecutive identical characters
                while (i < len && current[i] == digit) {
                    count++;
                    i++;
                }

                // Append count followed by the digit
                next_term += std::to_string(count) + digit;
            }

            current = next_term;
        }

        return current;
    }
};