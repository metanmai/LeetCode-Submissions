class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        
        def perms(p):
            if len(p) == len(nums):
                permutations.append(p[ : ])
                return
            
            for i in range(len(nums)):
                if nums[i] not in p:
                    p.append(nums[i])
                    perms(p)
                    p.pop()
        
        perms([])
        return permutations