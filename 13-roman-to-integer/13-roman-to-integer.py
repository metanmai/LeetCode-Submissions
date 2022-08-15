class Solution:
    def romanToInt(self, s: str) -> int:
        d = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000,
        }
        
        s += ' '
        number = 0
        
        for i in range(len(s) - 1):
            if s[i] == 'I':
                if s[i + 1] == 'V' or s[i + 1] == 'X':
                    number -= 1
                else:
                    number += 1
                    
            elif s[i] == 'X':
                if s[i + 1] == 'L' or s[i + 1] == 'C':
                    number -= 10
                else:
                    number += 10
            
            elif s[i] == 'C':
                if s[i + 1] == 'D' or s[i + 1] == 'M':
                    number -= 100
                else:
                    number += 100
            
            else:
                number += d[s[i]]
        
        return number
            
            