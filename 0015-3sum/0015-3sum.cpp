// Two-Pointer Approach.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        
        while(i < n)
        {
            int j = i + 1, k = n - 1;
            
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                
                else
                {
                    answer.push_back({nums[i], nums[j], nums[k]});
                    j = upper_bound(nums.begin() + j, nums.end(), nums[j]) - nums.begin();
                    k = upper_bound(nums.begin() + j, nums.end(), nums[k] - 1) - nums.begin() - 1;
                }
            }
            
            i = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
        }
        
        return answer;
    }
};