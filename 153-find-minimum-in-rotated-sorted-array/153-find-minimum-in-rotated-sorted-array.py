class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1] or len(nums) == 1:
            return nums[0]
        
        l, r = 0, len(nums) - 1
        
        while l <= r:
            mid = (l + r) // 2
            if mid != len(nums):
                if nums[mid] > nums[mid + 1]:
                    return nums[mid + 1]
                
                if nums[mid] < nums[mid - 1]:
                    return nums[mid]
                else:
                    if nums[0] < nums[mid]:
                        l = mid + 1
                    else:
                        r = mid - 1