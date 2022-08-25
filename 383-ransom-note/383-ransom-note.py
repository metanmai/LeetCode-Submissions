class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_freq = defaultdict(lambda : 0)
        
        for i in magazine:
            mag_freq[i] += 1
        
        for i in ransomNote:
            if mag_freq[i] == 0:
                return False
            
            else:
                mag_freq[i] -= 1
        
        return True
                