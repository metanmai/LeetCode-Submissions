class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        answer = []
        
        def createPattern(s):
            d = {}
            k = 1
            patt = []
            for i in s:
                if i not in d:
                    d[i] = k
                    k += 1
                
                patt.append(d[i])
                
            return tuple(patt)
        
        pattern = createPattern(pattern)
        
        for i in words:
            if pattern == createPattern(i):
                answer.append(i)
        
        return answer