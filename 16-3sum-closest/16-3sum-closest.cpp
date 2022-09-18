class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2], l, r, currSum;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            l = i + 1, r = nums.size() - 1;
            while(l < r)
            {
                currSum = nums[i] + nums[l] + nums[r];
                if(currSum > target) // Decrement r as much as possible then start incrementing l. 
                    r--;
                else
                    l++;

                if(abs(currSum - target) < abs(closest - target))
                    closest = currSum;
            }
        }
        
        return closest;
    }
};