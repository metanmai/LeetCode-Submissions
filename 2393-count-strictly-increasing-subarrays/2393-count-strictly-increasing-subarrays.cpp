class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        int i = 0;
        
        for(int j = 0; j < n; j++)
        {
            if(j + 1 == n or nums[j + 1] <= nums[j])
            {
                answer += (long long) (j - i + 1) * (j - i + 2) / 2;
                i = j + 1;
            }
        }
        
        return answer;
    }
};