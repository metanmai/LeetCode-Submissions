class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump = 0
        
        for i in range(len(nums)):
            if i > maxJump:
                return False
            else:
                maxJump = max(i + nums[i], maxJump)
        
        return maxJump >= len(nums) - 1