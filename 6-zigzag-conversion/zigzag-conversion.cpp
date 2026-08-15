#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Base cases
        if (numRows <= 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            // Change direction when reaching top or bottom row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};