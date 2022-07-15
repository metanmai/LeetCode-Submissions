class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = set()

        def dfs(x,y):
            if (x >= len(grid) or y >= len(grid[0]) or 
               x < 0 or y < 0 or (x, y) in visited or 
               grid[x][y] == 0):
                 return 0
            
            visited.add((x, y))
            count = (1 + dfs(x, y + 1) +
                     dfs(x + 1, y) +
                     dfs(x - 1, y) +
                     dfs(x, y - 1))
            return count
            
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and (i,j) not in visited:
                    max_area = max(dfs(i,j), max_area)
        return max_area