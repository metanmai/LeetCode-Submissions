class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size(), minDiff = INT_MAX;
        set<int> visited;
        
        for(int i = x; i < n; i++)
        {
            visited.insert(nums[i - x]);
            
            auto num = visited.upper_bound(nums[i]);
            
            if(num != visited.begin())
                minDiff = min(minDiff, nums[i] - *prev(num));
            
            if(num != visited.end())
                minDiff = min(minDiff, *num - nums[i]);
        }
        
        return minDiff;
    }
};