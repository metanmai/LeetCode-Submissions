class Solution:
    def jump(self, nums: List[int]) -> int:
        
        def jumpp(x):
            if x == 0:
                return 0

            for i in range(x, -1, -1):
                if i + nums[i] >= x:
                    maxJump = i
        
            return 1 + jumpp(maxJump)
        
        return jumpp(len(nums) - 1)