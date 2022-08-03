class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        n -= 1
        
        for i in range(n):
            s2 = ""
            letter = s[0]
            count = 0
            
            for j in s:
                if j == letter:
                    count += 1
                else:
                    s2 += str(count) + letter
                    count = 1
                    letter = j
            
            s2 += str(count) + letter
            
            s = s2
        
        return s