class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin(); i != nums.end() - 1; i++)
            if(*i == *(i + 1))
                return true;
        return false;
    }
};