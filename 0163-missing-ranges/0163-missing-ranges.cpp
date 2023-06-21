class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> answer;
        
        int val = lower;
        nums.push_back(upper + 1);
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > val)
            {
                answer.push_back({val, nums[i] - 1});
                val = nums[i];
            }
            
            val++;
        }
        
        return answer;
    }
};