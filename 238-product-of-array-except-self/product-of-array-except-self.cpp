class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // The output array does not count as extra space for complexity analysis
        vector<int> result(n, 1); 
        
        // Pass 1: Calculate left products
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            // Store the product of everything to the left of i
            result[i] = left_product;
            // Update the running left product for the next iteration
            left_product *= nums[i];
        }
        
        // Pass 2: Calculate right products and multiply with left products
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            // Multiply the existing left product by everything to the right
            result[i] *= right_product;
            // Update the running right product for the next iteration (moving left)
            right_product *= nums[i];
        }
        
        return result;
    }
};