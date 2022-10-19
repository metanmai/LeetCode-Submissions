class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        d = {}
        words = s.split()
        
        if len(pattern) != len(words):
            return False
        
        # Map every character in pattern to a word, and every word to a character.
        # No word should be mapped to more than one character.
        
        for i in range(len(pattern)):
            if pattern[i] not in d:
                if words[i] not in d.values():
                    d[pattern[i]] = words[i]
                
                else:
                    return False
            
            elif d[pattern[i]] != words[i]:
                return False
        
        return True