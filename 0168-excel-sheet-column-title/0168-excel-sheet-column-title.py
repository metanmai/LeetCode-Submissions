class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        base26 = ""
        
        while columnNumber > 0:
            base26 += alphabets[columnNumber % 26 - 1]
            
            quotient = columnNumber // 26
            
            if columnNumber % 26 == 0:
                quotient -= 1
                
            columnNumber = quotient
            
        return base26[::-1]