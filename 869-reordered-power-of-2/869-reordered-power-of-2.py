class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        
        def sortString(s):
            l = list(s)
            l2 = sorted(l, reverse = True)
            s = ""
            for i in l2:
                s += i
                
            return s
        
        x = str(n)
        x2 = sortString(x)
        n = int(x2)
        i = 1
        
        while i <= n:
            s = str(i)
            s2 = sortString(s)
            
            if s2 == x2:
                return True
            
            i *= 2
            
        return False