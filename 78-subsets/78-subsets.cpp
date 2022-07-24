class Solution {
public:
    vector<int> subset;
    vector<vector<int>> ans;
    
    void generate_subsets(int start, int len, vector<int> nums)
    {
        for(int i = start; i < len; i++)
        {
            subset.push_back(nums[i]);
            ans.push_back(subset);
            generate_subsets(i + 1, len, nums);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(subset);
        generate_subsets(0, nums.size(), nums);
        return ans;
    }
};