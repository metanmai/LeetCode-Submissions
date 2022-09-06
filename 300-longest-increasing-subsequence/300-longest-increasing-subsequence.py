# O(nlogn) algorithm

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tempSubseq = [nums[0]]
        length = 1
        
        for i in range(1, len(nums)):
            if nums[i] > tempSubseq[-1]:
                tempSubseq.append(nums[i])
                length += 1
            
            else:
                # Binary Search the leftmost index position.
                insert = bisect_left(tempSubseq, nums[i])
                tempSubseq[insert] = nums[i]
                
        return length