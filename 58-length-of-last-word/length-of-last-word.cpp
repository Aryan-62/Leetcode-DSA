#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip any trailing spaces at the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters of the last word until a space or the start of the string
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};