class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        subset = []
        nums.sort()
        unique = set()
        
        def backtrack(start):
            for i in range(start, len(nums)):
                subset.append(nums[i])
                if tuple(subset) not in unique:
                    ans.append(subset.copy())
                    unique.add(tuple(subset))
                backtrack(i + 1)
                subset.pop()
        
        backtrack(0)
        return ans