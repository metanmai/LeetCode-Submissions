class Solution:
    def minMoves(self, nums: List[int]) -> int:
        count, minimum_index = 0, 0
        for i in range(len(nums)):
            minimum_index = i if nums[i] < nums[minimum_index] else minimum_index
            
        for i in range(len(nums)):
            if i != minimum_index:
                count += nums[i] - nums[minimum_index]
        
        return count