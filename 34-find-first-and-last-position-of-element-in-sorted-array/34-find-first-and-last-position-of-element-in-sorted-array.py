class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def indexOf(position, mid):
            if position == 0:
                l, r = 0, mid
                
                if nums[l] == target:
                    return l
                
                while l <= r:
                    mid = (l + r) // 2
                    if nums[mid] == target and nums[mid - 1] != target:
                        return mid
                    
                    elif nums[mid] != target:
                        l = mid + 1
                    
                    else:
                        r = mid - 1
            
            else:
                l, r = mid, len(nums) - 1
                
                if nums[r] == target:
                    return r
                
                while l <= r:
                    mid = (l + r) // 2
                    if nums[mid] == target and nums[mid + 1] != target:
                        return mid
                    
                    elif nums[mid] != target:
                        r = mid - 1
                    
                    else:
                        l = mid + 1
        
        answer = [-1, -1]
        l, r = 0, len(nums) - 1
        
        while l <= r:
            mid = (l + r) // 2
            
            if nums[mid] == target:
                # First Index
                answer[0] = indexOf(0, mid)
                
                # Last Index
                answer[1] = indexOf(1, mid)
                
                return answer
            
            elif nums[mid] < target:
                l = mid + 1
            
            else:
                r = mid - 1
        
        return answer
    