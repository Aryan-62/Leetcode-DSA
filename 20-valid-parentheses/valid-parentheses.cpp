#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            // Push the corresponding closing bracket onto the stack
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } 
            // If it's a closing bracket, check for mismatch or empty stack
            else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop(); // Matching pair found
            }
        }

        // If stack is empty, all brackets matched correctly
        return st.empty();
    }
};