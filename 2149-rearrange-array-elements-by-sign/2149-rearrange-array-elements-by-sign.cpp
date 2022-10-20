class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // +ve numbers are in even indices, negative numbers in odd indices.
        int n = nums.size();
        vector<int> nums2, nums3, ans;
        for(int i = 0; i < n; i++)
            if(nums[i] > 0)
                nums2.push_back(nums[i]);
        
        for(int i = 0; i < n; i++)
            if(nums[i] < 0)
                nums3.push_back(nums[i]);
        
        for(int i = 0; i < n / 2; i++)
        {
            ans.push_back(nums2[i]);
            ans.push_back(nums3[i]);
        }
        
        return ans;
    }
};