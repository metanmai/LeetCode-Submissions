class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        d = defaultdict(lambda : 0)
        
        for i in arr:
            d[i] += 1
        
        d = {k: v for k, v in sorted(d.items(), key = lambda item: item[1], 
                                     reverse = True)}
        
        l, count = len(arr), 0
        for i in d:
            if l > len(arr) // 2:
                l -= d[i]
            else:
                break
            
            count += 1
        
        return count