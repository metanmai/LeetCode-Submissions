class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        
        maps = ["-", "-", "abc", "def","ghi","jkl","mno", "pqrs", "tuv", "wxyz"]
        answer = []
        
        def combos(num, comb):
            if len(comb) == len(digits):
                answer.append(comb[ : ])
                return
            
            for i in range(num, len(digits)):
                for j in range(len(maps[int(digits[i])])):
                    comb += maps[int(digits[i])][j]
                    combos(i + 1, comb)
                    comb = comb[ : -1]
                    
        combos(0, "")
        return answer