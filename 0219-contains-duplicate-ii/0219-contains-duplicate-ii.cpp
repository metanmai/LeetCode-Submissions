class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp; // {element, index}.
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end() and i - mp[nums[i]] <= k)
                    return true;
            
            mp[nums[i]] = i;
        }
        
        return false;
    }
};