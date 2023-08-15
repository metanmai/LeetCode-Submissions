#define ll long long

class Solution {
public:
    ll maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll currSum = 0, maxSum = 0;
        map<int, int> currWindow;
        
        for(int i = 0; i < n; i++)
        {
            currWindow[nums[i]]++, currSum += nums[i];
            
            if(currWindow.size() == k)
            maxSum = max(maxSum, currSum);
            
            if(i < k - 1)
                continue;
            
            currWindow[nums[i - k + 1]]--, currSum -= nums[i - k + 1];

            if(currWindow[nums[i - k + 1]] == 0)
                currWindow.erase(nums[i - k + 1]);
        }
        
        return maxSum;
    }
};