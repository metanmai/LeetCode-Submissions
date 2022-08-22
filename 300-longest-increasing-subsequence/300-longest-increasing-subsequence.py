# O(n) algorithm

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        maxSubseqLength = [1] * len(nums)
        
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    maxSubseqLength[i] = max(maxSubseqLength[i], 1 + maxSubseqLength[j])
        
        return max(maxSubseqLength)