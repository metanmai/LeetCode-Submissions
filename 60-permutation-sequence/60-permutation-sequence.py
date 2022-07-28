class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        l = [i for i in range(1, n + 1)]
        
        def permute(l, n, k):
            if n == 0:
                return ""
            
            fact = factorial(n - 1)
            index = (k - 1) // fact
            
            return str(l.pop(index)) + permute(l, n - 1, k % fact)
        
        return permute(l, n, k)