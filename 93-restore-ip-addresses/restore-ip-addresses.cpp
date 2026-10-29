#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        // An IP address must have between 4 and 12 digits
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        
        string current = "";
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int startIndex, int dots, string current, vector<string>& result) {
        // Base case: placed 3 dots, creating 4 parts
        if (dots == 3) {
            string lastSegment = s.substr(startIndex);
            if (isValid(lastSegment)) {
                result.push_back(current + lastSegment);
            }
            return;
        }

        // Try segment lengths of 1, 2, and 3
        for (int len = 1; len <= 3 && startIndex + len < s.length(); ++len) {
            string segment = s.substr(startIndex, len);
            if (isValid(segment)) {
                backtrack(s, startIndex + len, dots + 1, current + segment + ".", result);
            }
        }
    }

    bool isValid(const string& seg) {
        // Must be 1 to 3 characters long
        if (seg.empty() || seg.length() > 3) return false;
        
        // Cannot have leading zero unless it's just "0"
        if (seg.length() > 1 && seg[0] == '0') return false;
        
        // Value must be between 0 and 255
        int val = stoi(seg);
        return val >= 0 && val <= 255;
    }
};