class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0;
        long long answer = 0;
        
        while(i < n)
        {
            if(nums[i] == 0)
            {
                int j = i;
                long long count = 0;
                while(j < n and nums[j] == 0)
                {
                    count++, j++;
                }
                
                i = j;
                answer += count * (count + 1) / 2;
            }
            
            i++;
        }
        
        return answer;
    }
};