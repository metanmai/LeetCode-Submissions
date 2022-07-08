# Using Dynamic Programming

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = {}
        
        def paths(m, n):
            f = frozenset([m, n])
            
            if f in d:
                return d[f]
            
            elif m == 1 or n == 1:
                return 1
            
            else:
                d[f] = paths(m - 1, n) + paths(m, n - 1)
                return d[f]
        
        return paths(m, n)