class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = 0;
        
        for (int num : nums) {
            // If our running total is dragging us down (negative), 
            // reset it and start fresh with the current number.
            if (current_sum < 0) {
                current_sum = 0;
            }
            
            // Add the current number to our running total
            current_sum += num;
            
            // Update the absolute maximum sum we've seen so far
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};