class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), answer = nums[0], cnt = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(cnt == 0)
                answer = nums[i];
            
            cnt += nums[i] == answer ? 1 : -1;
        }
        
        cnt = 0;
        
        // This second pass is to check if the majority element actually exists.
        for(int num : nums)
            cnt += num == answer;
        
        return answer;
    }
};