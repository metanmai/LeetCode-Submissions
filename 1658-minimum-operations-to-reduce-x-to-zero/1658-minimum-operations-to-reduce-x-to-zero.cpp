class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0), currSum = 0;
        int n = nums.size(), l = 0, r = 0, minMoves = INT_MAX, target = totalSum - x;
        
        while(r <= n)
        {
            while(l < r and currSum > target)
                currSum -= nums[l], l++;
            
            if(currSum == target)
                minMoves = min(minMoves, n - r + l);
            
            if(r == n)
                break;
            
            currSum += nums[r], r++;
        }
        
        return minMoves == INT_MAX ? -1 : minMoves;
    }
};