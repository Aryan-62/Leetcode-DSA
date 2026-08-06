class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // The height of the water is limited by the shorter line
            int current_height = min(height[left], height[right]);
            
            // The width is the distance between the two lines
            int current_width = right - left;
            
            // Calculate the area and update the max if it's larger
            int current_area = current_height * current_width;
            max_water = max(max_water, current_area);
            
            // Move the pointer of the shorter line inward
            // If they are equal, moving either is fine
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};