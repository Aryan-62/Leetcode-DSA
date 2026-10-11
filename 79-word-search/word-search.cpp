#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();

        // Pruning 1: Word length exceeds total available cells
        if (len > m * n) return false;

        // Count character frequencies
        std::unordered_map<char, int> board_counts;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                board_counts[board[r][c]]++;
            }
        }

        // Pruning 2: Grid lacks enough characters to form word
        for (char ch : word) {
            if (--board_counts[ch] < 0) {
                return false;
            }
        }

        // Pruning 3: Reverse word if the first character is more frequent than the last
        // Counting occurrences from the earlier decrement step:
        int first_char_count = 0, last_char_count = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word.front()) first_char_count++;
                if (board[r][c] == word.back())  last_char_count++;
            }
        }
        if (first_char_count > last_char_count) {
            std::reverse(word.begin(), word.end());
        }

        // Run Backtracking DFS
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0, m, n)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, 
             int r, int c, int idx, int m, int n) {
        if (idx == word.length()) return true;

        // Boundary checks and mismatch
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx]) {
            return false;
        }

        // Reached the last character successfully
        if (idx == word.length() - 1) return true;

        // In-place marking to save memory
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions: down, up, right, left
        static const int dr[] = {1, -1, 0, 0};
        static const int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            if (dfs(board, word, r + dr[i], c + dc[i], idx + 1, m, n)) {
                board[r][c] = temp; // Restore before returning
                return true;
            }
        }

        // Backtrack
        board[r][c] = temp;
        return false;
    }
};