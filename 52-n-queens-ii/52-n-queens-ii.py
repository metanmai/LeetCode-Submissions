class Solution:
    def totalNQueens(self, n: int) -> int:
        answer = [0]
        
        def queen(col, dgn1, dgn2, i):
            if i == n:
                answer[0] += 1
                return
            
            for j in range(n):
                if j not in col and i - j not in dgn1 and i + j not in dgn2:
                    col.add(j), dgn1.add(i - j), dgn2.add(i + j)
                    queen(col, dgn1, dgn2, i + 1)
                    col.remove(j), dgn1.remove(i - j), dgn2.remove(i + j)
        
        queen(set(), set(), set(), 0)
        
        return answer[0]
        