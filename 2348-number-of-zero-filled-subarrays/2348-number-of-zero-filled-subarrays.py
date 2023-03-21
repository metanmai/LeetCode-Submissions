class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = 0
        l, r = 0, 0
        while l < len(nums):
            if nums[r] == 0:
                while r < len(nums) and nums[r] == 0:
                    r += 1
                res += (r - l) * (r - l + 1) // 2
            else:
                r += 1
            l = r
        
        return res