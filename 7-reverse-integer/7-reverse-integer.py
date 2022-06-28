class Solution:
    def reverse(self, x: int) -> int:
        neg = -1 if x < 0 else 1
        x *= neg
        
        length = len(str(x))
        
        ans, i = 0, 1
        while x > 0:
            r = x % 10
            x //= 10
            ans += pow(10, length - i) * r
            i += 1
        
        ans *= neg
        return 0 if ans < -(2 ** 31) or ans > 2 ** 31 - 1 else ans