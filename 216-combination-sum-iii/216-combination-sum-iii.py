class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        answer = []
        candidates = [i for i in range(1, 10)]
        
        if sum(candidates) == n:
            answer.append(candidates)
            return answer
        
        candidates.sort()
        combos = set()
        def combinations(combo, target, start):
            if target == 0 and len(combo) == k:
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
                
        
        combinations([], n, 0)
            
        return list(combos)
                