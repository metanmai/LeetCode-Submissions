class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        # Key = Remainder, Value = Index
        d = {0 : -1}
        running_sum = 0
            
        for i in range(len(nums)):
            running_sum += nums[i]
            if running_sum % k not in d:
                d[running_sum % k] = i
                
            elif i - d[running_sum % k] >= 2:
                    return True
            
        return False