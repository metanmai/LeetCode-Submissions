class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        answer = []
        nums3 = nums1.copy()
        nums3 = nums1.copy()

        l1, l2, c1, c2 =len(nums1), len(nums2), 0, 0
        def removeDuplicates(x):
            temp = set()
            temp2 = []
            for i in x:
                temp.add(i)
            for i in temp:
                temp2.append(i)
            return temp2

        k = 0
        while len(nums1):
            if nums1[k] in nums2:  
                nums1.remove(nums1[k])
            else: k += 1
            c1 += 1
            if c1 == l1:
                break

        answer.append(removeDuplicates(nums1))
        k = 0
        while len(nums2):
            if nums2[k] in nums3:
                nums2.remove(nums2[k])
            else: k += 1
            c2 += 1
            if c2 == l2:
                break

        answer.append(removeDuplicates(nums2))
        
        return answer