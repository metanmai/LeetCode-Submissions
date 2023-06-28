class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), answer = 0, maxLen = 1;;
        
        vector<int> length(n, 1), tally(n, 1);
        
        for(int i = n - 1; i >= 0; i--)
        {
            int maxVal = 0;
            
            for(int j = i + 1; j < n; j++)
                if(nums[i] < nums[j])
                    maxVal = max(maxVal, length[j]);
            
            length[i] = max(length[i], maxVal + 1);
            
            int count = 0;
            
            for(int j = i + 1; j < n; j++)
                if(nums[i] < nums[j] and length[j] == length[i] - 1)
                    tally[i] = max(tally[i], count += tally[j]);
            
            maxLen = max(maxLen, length[i]);
        }
        
        for(int i = 0; i < n; i++)
            if(length[i] == maxLen)
                answer += tally[i];
        
        return answer;
    }
};