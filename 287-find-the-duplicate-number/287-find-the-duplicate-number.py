class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        dups = set()
        i = 0
       
        while nums[i] not in dups:
            dups.add(nums[i])
            i += 1
        
        return nums[i]
        