class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), lastPos = 0, i = 0;
        
        while(i < n)
        {
            int initialNum = nums[i];
            
            while(i < n and nums[i] == initialNum)
                i++;
            
            nums[lastPos++] = initialNum;
        }
        
        return lastPos;
    }
};