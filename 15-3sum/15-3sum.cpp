class Solution {
public:
    vector<vector<int>> res;
        
    void twoSum(vector<int> nums, int i)
    {
        unordered_set<int> seen;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int complement = -nums[i] - nums[j];
            if (seen.count(complement))
            {
                res.push_back({nums[i], complement, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    ++j;
            }
            seen.insert(nums[j]);
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() and nums[i] <= 0; i++)
            if(i == 0 or nums[i - 1] != nums[i]) // To eliminate duplicates.
                twoSum(nums, i);
        
        return res;
    }
};