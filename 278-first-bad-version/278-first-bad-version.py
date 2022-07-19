# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low, high = 1, n - 1
        while low <= high:
            mid = (low + high) // 2
            if isBadVersion(mid + 1) and not isBadVersion(mid):
                return mid + 1
            elif isBadVersion(mid + 1):
                high = mid - 1
            else:
                low = mid + 1
        
        return 1