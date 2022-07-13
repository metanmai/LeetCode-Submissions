class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefix_sum = []
        
        s = 0
        for i in nums:
            s += i
            prefix_sum.append(s)
        
        prefix_sum = [0] + prefix_sum
        
        for i in range(len(nums)):
            if prefix_sum[i] == prefix_sum[-1] - prefix_sum[i] - nums[i]:
                return i
        
        return -1