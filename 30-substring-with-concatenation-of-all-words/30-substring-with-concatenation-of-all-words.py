class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        answer = []
        d = {}
        total_words = len(set(words))
        length = len(words[0])
        
        for i in words:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        
        for i in range(len(s) - len(words) * length + 1):
            count = 0
            d2 = d.copy()
            window = s[i : i + length]
            k = i
            while (window in d and d[window] > 0 and 
                   k < len(s) - length + 1):
                d[window] -= 1
                k += length
                window = s[k : k + length]
            
            for j in d:
                if d[j] == 0:
                    count += 1
            
            if count == total_words:
                answer.append(i)
            
            d = d2
        
        return answer