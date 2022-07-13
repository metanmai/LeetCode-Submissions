class Solution:
    def canJump(self, nums: List[int]) -> bool:
        jumpIndex = len(nums) - 1
        
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= jumpIndex:
                jumpIndex = i
        
        return jumpIndex == 0