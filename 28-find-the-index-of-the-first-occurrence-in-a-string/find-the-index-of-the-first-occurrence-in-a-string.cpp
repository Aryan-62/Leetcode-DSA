#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        size_t index = haystack.find(needle);
        
        if (index != std::string::npos) {
            return static_cast<int>(index);
        }
        return -1;
    }
};