class Solution {
    public boolean canJump(int[] nums) {
        int maxJump = 0, n = nums.length;
        
        for(int i = 0; i < n; i++)
            if(i <= maxJump && nums[i] + i > maxJump)
                maxJump = nums[i] + i;
        
        return maxJump >= n - 1;
    }
}