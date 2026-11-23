#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        
        // Out of bounds or not an unvisited 'O'
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }
        
        // Mark as safe (connected to border)
        board[r][c] = '#';
        
        // Explore all 4 adjacent directions
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // 1. Traverse the left and right borders
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        
        // 2. Traverse the top and bottom borders
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        
        // 3. Flip surrounded 'O's to 'X's and restore safe '#'s to 'O's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};