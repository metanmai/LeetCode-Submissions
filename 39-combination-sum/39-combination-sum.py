class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answer = []
        
        def combinations(combo, target, start):
            if target == 0:
                answer.append(combo[ : ])
                return
            
            if target < 0:
                return
            
            for i in range(start, len(candidates)):
                combo.append(candidates[i])
                combinations(combo, target - candidates[i], i)
                combo.pop()
                
        
        combinations([], target, 0)
        return answer
                