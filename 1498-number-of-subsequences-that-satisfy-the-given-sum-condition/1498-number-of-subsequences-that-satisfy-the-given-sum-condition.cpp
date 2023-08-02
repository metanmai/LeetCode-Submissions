class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        int n = nums.size(), answer = 0;
        vector<int> pows(n, 1);
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < n; i++)
            pows[i] = pows[i - 1] * 2 % MOD;
        
        for(int i = 0; i < n; i++)
        {
            int maxNumPos = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
            
            int diff = maxNumPos - i;
            
            if(diff > 0)
                answer = (answer + pows[diff] % MOD) % MOD;
            
            else
                answer += nums[i] * 2 <= target;
        }
        
        return answer;
    }
};