class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        island = 0
        
        def dfs(x, y):
            if not (x >= len(grid) or y >= len(grid[0]) or 
               x < 0 or y < 0 or (x, y) in visited or 
               grid[x][y] == "0"):
                 
                visited.add((x, y))
                dfs(x, y + 1)
                dfs(x + 1, y)
                dfs(x - 1, y)
                dfs(x, y - 1)
  
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1" and (i,j) not in visited:
                    dfs(i,j)
                    island += 1
                    
        return island