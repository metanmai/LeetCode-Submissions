class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        columns = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        boxes = collections.defaultdict(set)
        
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue
                    
                elif (board[i][j] in rows[i] or 
                      board[i][j] in columns[j] or 
                      board[i][j] in boxes[(i // 3, j //3)]):
                    return False
                
                else:
                    columns[j].add(board[i][j])
                    rows[i].add(board[i][j])
                    boxes[(i // 3, j // 3)].add(board[i][j])
                    
        return True