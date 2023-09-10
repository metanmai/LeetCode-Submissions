class Solution {
private:
    int findGCD(int x, int y)
    {
        if(y > x)
            return findGCD(y, x);
        
        if(y == 0)
            return x;
        
        return findGCD(y, x % y);
    }
    
    int findMaxScore(vector<int> &dp, vector<int> &nums, 
                     int mask, int ops, int bits, int n)
    {
        if(mask == bits)
            return 0;
        
        if(dp[mask] != -1)
            return dp[mask];
        
        int score = 0;
        
        for(int i = 0; i < 2 * n; i++)
        {
            if(mask & (1 << i))
                continue;
            
            mask = mask ^ (1 << i);
            
            for(int j = i + 1; j < 2 * n; j++)
            {
                if(mask & (1 << j))
                   continue;
                
                score = max(score, 
                            (ops * findGCD(nums[i], nums[j]) + findMaxScore(dp, nums, mask | (1 << j), ops + 1, bits, n)));
            }
            
            mask = mask ^ (1 << i);
        }
        
        return dp[mask] = score;
    }
    
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size() / 2, bits = pow(2, 2 * n) - 1;
        vector<int> dp(bits + 1, -1);
        
        return findMaxScore(dp, nums, 0, 1, bits, n);
    }
};