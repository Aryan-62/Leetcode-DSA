#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;

        // Split by delimiter '/'
        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }

        // Build the canonical path
        std::string canonicalPath = "";
        for (const std::string& dir : stack) {
            canonicalPath += "/" + dir;
        }

        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};