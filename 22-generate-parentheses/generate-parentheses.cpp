#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(int open, int close, int n, string current, vector<string>& result) {
        // Base case: combination is complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Rule 1: Can we place an opening bracket?
        if (open < n) {
            backtrack(open + 1, close, n, current + "(", result);
        }

        // Rule 2: Can we place a closing bracket?
        if (close < open) {
            backtrack(open, close + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};