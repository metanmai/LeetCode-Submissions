class Solution {
public:
    vector<int> subset;
    vector<vector<int>> ans;
    
    void generate_subsets(int start, vector<int> nums)
    {
        for(int i = start; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            ans.push_back(subset);
            generate_subsets(i + 1, nums);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(subset);
        generate_subsets(0, nums);
        return ans;
    }
};