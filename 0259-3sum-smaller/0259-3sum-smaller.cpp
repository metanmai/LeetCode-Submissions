class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size(), answer = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int val = target - nums[i] - nums[j];
                int pos = lower_bound(nums.begin() + j + 1, nums.end(), val) - nums.begin();
                
                answer += pos - (j + 1);
            }
        }
        
        return answer;
    }
};