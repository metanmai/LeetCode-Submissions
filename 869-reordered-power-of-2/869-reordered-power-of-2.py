class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        # Run a while loop till the highest permutation on n (Eg : 4210 for 1024)
        # Check if any power of 2 is a permutation of this number.
        def sortString(s):
            l = sorted(s, reverse = True)
            s = ""
            for i in l:
                s += i
                
            return s
        
        n_str = sortString(str(n))
        n = int(n_str)
        i = 1
    
        while i <= n:
            if sortString(str(i)) == n_str:
                return True
            
            i *= 2
            
        return False