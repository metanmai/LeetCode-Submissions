/* 
Prefix/Suffix Max Solution
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), totalWater = 0;
        vector<int> prefixMax(n, height.front()), suffixMax(n, height.back());
        
        for(int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        
        for(int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        
        for(int i = 0; i < n; i++)
            totalWater += min(prefixMax[i], suffixMax[i]) - height[i];
        
        return totalWater;
    }
};