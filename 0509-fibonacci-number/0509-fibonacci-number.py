class Solution:
    def fib(self, n: int) -> int:
        t1, t2 = 0, 1
        
        for i in range(2, n + 1):
            t3 = t1 + t2
            t1, t2 = t2, t3
        
        return t3 if n >= 2 else n