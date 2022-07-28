class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        answer = []
        if sum(candidates) == target:
            answer.append(candidates)
            return answer
        candidates.sort()
        combos = set()
        def combinations(combo, target, start):
            if target == 0:
                combos.add(tuple(combo))
                return
            
            if target < 0:
                return
            prev = -1
            for i in range(start, len(candidates)):
                if candidates[i] == prev:
                    continue
                combo.append(candidates[i])
                combinations(combo, target - candidates[i], i + 1)
                combo.pop()
                prev = candidates[i]
                
        
        combinations([], target, 0)
        
        #comb = sorted(combos)
        #for i in comb:
         #   temp = []
          #  for j in i:
           #answer.append(temp)
            
        return list(combos)
                