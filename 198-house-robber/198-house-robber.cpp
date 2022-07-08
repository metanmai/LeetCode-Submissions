class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_max = 0, curr_max = 0, temp;
        for(int i = 0; i< nums.size(); i++)
        {
            temp = max(curr_max, prev_max + nums[i]);
            prev_max = curr_max;
            curr_max = temp;
        }
        
        return curr_max;
    }
};