class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int zero = 0, nonZero = 0; nonZero < nums.size(); nonZero++)
            if(nums[nonZero])
                swap(nums[nonZero], nums[zero++]);
    }
};