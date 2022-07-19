class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        def binarySearch(nums, low, high, target):
            mid = (low + high) // 2
            if nums[mid] == target:
                return mid
            
            elif low > high:
                return -1
            
            elif nums[mid] > target:
                return binarySearch(nums, low, mid - 1, target)
            
            elif nums[mid] < target:
                return binarySearch(nums, mid + 1, high, target)
        
        return binarySearch(nums, 0, len(nums) - 1, target)