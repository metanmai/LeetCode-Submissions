class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        answer = []
        board = [["." for i in range(n)] for i in range(n)]
        
        def convertBoard(board):
            newBoard = []
            
            for row in board:
                s = ""
                for col in row:
                    s += col
                newBoard.append(s)
                
            return newBoard
        
        def queen(board, col, dgn1, dgn2, i):
            if i == n:
                answer.append(convertBoard(board))
                return
            
            for j in range(n):
                if j not in col and i - j not in dgn1 and i + j not in dgn2:
                    board[i][j] = "Q"
                    col.add(j), dgn1.add(i - j), dgn2.add(i + j)
                    queen(board.copy(), col, dgn1, dgn2, i + 1)
                    board[i][j] = "."
                    col.remove(j), dgn1.remove(i - j), dgn2.remove(i + j)
        
        queen(board.copy(), set(), set(), set(), 0)
        
        return answer