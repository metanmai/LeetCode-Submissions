class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_count = 0;
        
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            if(*i == 0)
                count = 0;
            else
                count++;
            
            max_count = max(max_count, count);
        }
        return max_count;
    }
};