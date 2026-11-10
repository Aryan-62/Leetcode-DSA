#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        // Step 1: Find the minimum and maximum values in the array
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        // If all elements are the same, the gap is 0
        if (min_val == max_val) return 0;
        
        // Step 2: Calculate bucket size and count
        // We use max(1, ...) to prevent division by zero in case of small ranges
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;
        
        // Step 3: Create buckets to store the min and max for each range
        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);
        
        // Place elements into their corresponding buckets
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
        }
        
        // Step 4: Calculate the maximum gap
        int max_gap = 0;
        int prev_max = min_val;
        
        for (int i = 0; i < bucket_count; ++i) {
            // Skip empty buckets
            if (bucket_min[i] == INT_MAX) continue;
            
            // The gap is current bucket's min minus the previous bucket's max
            max_gap = max(max_gap, bucket_min[i] - prev_max);
            prev_max = bucket_max[i];
        }
        
        return max_gap;
    }
};