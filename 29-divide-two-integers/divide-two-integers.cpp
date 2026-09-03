#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit signed overflow case: -2^31 / -1 = 2^31 (exceeds INT_MAX)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to prevent overflow during abs(INT_MIN)
        long long n = std::abs((long long)dividend);
        long long d = std::abs((long long)divisor);

        long long quotient = 0;

        // Subtract the largest possible shifted divisor at each step
        while (n >= d) {
            long long temp = d;
            long long multiple = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};