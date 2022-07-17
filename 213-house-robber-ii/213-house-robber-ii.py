class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        l1, l2 = nums[ : -1], nums[1 : ]
        rob1, rob2, rob3, rob4 = 0, 0, 0, 0
        
        
        for n in l1:
            temp = max(n + rob1, rob2)
            rob1 = rob2
            rob2 = temp
            
        for n in l2:
            temp = max(n + rob3, rob4)
            rob3 = rob4
            rob4 = temp
        
        return max(rob2, rob4)