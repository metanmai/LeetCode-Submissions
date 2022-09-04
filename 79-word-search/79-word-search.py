class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        r, c = len(board), len(board[0])
        visited = set()
        
        def dfs(x, y, i):
            if i == len(word):
                return True
            
            if(x < 0 or y < 0 or
               x >= r or y >= c or
               board[x][y] != word[i] or
               (x, y) in visited or board[x][y] != word[i]):
                return False
            
            visited.add((x, y))
            condition = (dfs(x + 1, y, i + 1) or
                    dfs(x - 1, y, i + 1) or
                    dfs(x, y + 1, i + 1) or
                    dfs(x, y - 1, i + 1))
            visited.remove((x, y))
            return condition
        
        for i in range(r):
            for j in range(c):
                    if dfs(i, j, 0):
                        return True

        return False