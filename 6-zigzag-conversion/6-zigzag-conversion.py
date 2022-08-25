class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows >= len(s) or numRows == 1:
            return s
        
        gap = 2 * (numRows - 1)
        initial_gap = gap
        answer = ""
        complement = 0
        
        for i in range(numRows):
            j = i

            count = 0
            while j < len(s):
                answer += s[j]
                if i == 0 or i == numRows - 1:
                    j += initial_gap
                
                elif count % 2 == 0:
                    j += gap
                else:
                    j += complement
                
                count += 1
            
            complement += 2
            gap -= 2
        
        return answer
            
            
        