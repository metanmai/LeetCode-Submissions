/* 
Two Pointer Solution
Time Complexity: O(n)
Space Complexity: O(1)

Similar Idea to Prefix/Suffix Max Solution.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0, left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while (left < right) 
        {
            
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : 
                                            totalWater += (left_max - height[left]);
                left++;
            }
            
            else 
            {
                height[right] >= right_max ? (right_max = height[right]) : 
                                              totalWater += (right_max - height[right]);
                right--;
            }
        }
        
        return totalWater;
    }
};