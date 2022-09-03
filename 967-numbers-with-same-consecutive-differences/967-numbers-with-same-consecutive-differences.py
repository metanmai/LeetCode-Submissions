class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        answer = []
        
        def dfs(s):
            if len(s) == n:
                answer.append(int(s))
                return
            
            for i in range(10):
                if abs(int(s[-1]) - i) == k:
                    s += str(i)
                    dfs(s)
                    s = s[ : -1]
        
        for i in range(1, 10):
            dfs(str(i))
        
        return answer