#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals primarily by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // If merged is empty or current interval does not overlap with the previous
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // There is an overlap, so merge the current interval into the previous one
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};