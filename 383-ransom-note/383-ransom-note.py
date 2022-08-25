class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_freq, ransom_freq = defaultdict(lambda : 0), defaultdict(lambda : 0)
        
        for i in magazine:
            mag_freq[i] += 1
        
        for i in ransomNote:
            ransom_freq[i] += 1
        
        for i in ransom_freq:
            if i not in mag_freq or mag_freq[i] < ransom_freq[i]:
                return False
        
        return True