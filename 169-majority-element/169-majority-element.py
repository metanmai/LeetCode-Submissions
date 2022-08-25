class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        
        for i in nums:
            """
            Change your assumption of what the majority element is every time
            count becomes zero. If it becomes zero at any point, that means there
            isn't more than n/2 of it, so it isn't the right answer.
            """
            if count == 0:
                maj = i
                count += 1
            
            else:
                if i == maj:
                    count += 1
                else:
                    count -= 1
        
        return maj