class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Accumulate digits & clamp
        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            
            // Clamp immediately if out of 32-bit bounds
            if (sign * num >= INT_MAX) return INT_MAX;
            if (sign * num <= INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return sign * num;
    }
};