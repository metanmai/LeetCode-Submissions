class Solution:
    def totalNQueens(self, n: int) -> int:
        answer = [0]
        board = [["." for i in range(n)] for i in range(n)]
        
        def queen(board, col, dgn1, dgn2, i):
            if i == n:
                answer[0] += 1
                return
            
            for j in range(n):
                if j not in col and i - j not in dgn1 and i + j not in dgn2:
                    board[i][j] = "Q"
                    col.add(j), dgn1.add(i - j), dgn2.add(i + j)
                    queen(board.copy(), col, dgn1, dgn2, i + 1)
                    board[i][j] = "."
                    col.remove(j), dgn1.remove(i - j), dgn2.remove(i + j)
        
        queen(board.copy(), set(), set(), set(), 0)
        
        return answer[0]
        