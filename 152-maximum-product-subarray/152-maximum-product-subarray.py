# https://youtu.be/lXVy6YWFcRM

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = max(nums)
        currMax, currMin = 1, 1
        
        for i in nums:
            temp = currMax
            currMax = max(currMax * i, currMin * i, i)
            currMin = min(temp * i, currMin * i, i)
            ans = max(ans, currMax)
        
        return ans