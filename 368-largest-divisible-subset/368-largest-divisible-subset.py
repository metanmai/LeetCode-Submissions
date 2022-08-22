class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        maxSubset = []
        nums.sort()
        longestSubset = [[i] for i in nums]
        
        for i in range(len(nums) - 1, -1, -1):
            plug = []
            for j in range(i + 1, len(nums)):
                if nums[j] % nums[i] == 0 and len(longestSubset[j]) > len(plug):
                    plug = longestSubset[j]
            longestSubset[i] += plug
            if len(longestSubset[i]) > len(maxSubset):
                maxSubset = longestSubset[i]
        
        return maxSubset
        