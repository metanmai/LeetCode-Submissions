class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        d = {}
        answer = []
        
        def freq(words):
            d = {}
            
            for i in words:
                if i not in d:
                    d[i] = 1
                else:
                    d[i] += 1
                    
            return d
        
        if len(words2) == 1:
            d = freq(words2[0])
        
        else:
            for i in range(len(words2) - 1):
                d1, d2 = freq(words2[i]), freq(words2[i + 1])

                for j in d1:
                    if j not in d or d1[j] > d[j]:
                        d[j] = d1[j]

                for j in d2:
                    if j not in d or d2[j] > d[j]:
                        d[j] = d2[j]
            
        for i in words1:
            D = freq(i)
            subset = True
            
            for j in d:
                if j not in D or d[j] > D[j]:
                    subset = False
                    break
            
            if subset:
                answer.append(i)
        
        return answer
                
                