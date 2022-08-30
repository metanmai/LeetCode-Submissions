class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key = len)
        chainLength = [1] * len(words)
        def isPredecessor(s1, s2):
            if not len(s2) - len(s1) == 1:
                return False
            
            i = 0
            while i < len(s1) and s1[i] == s2[i]:
                i += 1
            
            if i == len(s1):
                return True
            if s1[i] != s2[i]:
                s2 = s2[ : i] + s2[i + 1 : ]
            
            while i < len(s1) and s1[i] == s2[i]:
                i += 1
            
            return i == len(s1)
        
        for i in range(len(words) - 1, -1, -1):
            for j in range(i + 1, len(words)):
                if(isPredecessor(words[i], words[j]) or
                   isPredecessor(words[j], words[i])):
                    chainLength[i] = max(chainLength[i], 
                                         chainLength[j] + 1)
        
        return max(chainLength)