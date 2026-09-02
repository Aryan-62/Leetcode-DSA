#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track presence of digits (1-9) for:
        // 9 rows, 9 columns, and 9 3x3 sub-boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int digit = board[r][c] - '1'; // Map '1'-'9' to index 0-8
                int boxIdx = (r / 3) * 3 + (c / 3);

                // Check if the digit has already appeared in the row, column, or box
                if (rows[r][digit] || cols[c][digit] || boxes[boxIdx][digit]) {
                    return false;
                }

                // Mark the digit as seen
                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[boxIdx][digit] = true;
            }
        }

        return true;
    }
};
