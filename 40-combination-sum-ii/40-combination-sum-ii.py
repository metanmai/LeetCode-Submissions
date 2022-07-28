class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        d = {}
        answer = []
        candidates.sort()
        
        for i in candidates:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        
        def combinations(combo, target, start, d):
            if target == 0:
                answer.append(combo.copy())
            
            if target <= 0:
                return
            
            temp = list(d.keys())
            for i in range(len(temp)):
                if d[temp[i]] > 0:
                    combo.append(temp[i])
                    d[temp[i]] -= 1
                    combinations(combo, target - temp[i], i, d)
                    d[temp[i]] += 1
                    combo.pop()

        combinations([], target, 0, d)
        res = list(set(tuple(sorted(sub)) for sub in answer))
        return res