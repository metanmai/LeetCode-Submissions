class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        answer = []
        
        def combinations(start, comb):
            if len(comb) == k:
                answer.append(comb)
                return
            
            for i in range(start, n + 1):
                comb.append(i)
                combinations(i + 1, comb.copy())
                comb.pop()
                
        combinations(1, [])
        return answer