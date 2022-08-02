class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0
        
        def dfs(x, y):
            
            if(x not in range(len(grid)) or 
               y not in range(len(grid[0])) or
               grid[x][y] != 1):
                return 0
            
            grid[x][y] = 2
            
            directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
            perimeter = 0
            count = 0
            for dx, dy in directions:
                r, c = x + dx, y + dy

                if r not in range(len(grid)):
                    perimeter += 1

                if c not in range(len(grid[0])):
                    perimeter += 1

                if (r in range(len(grid)) and
                    c in range(len(grid[0])) and
                    grid[r][c] == 0):
                    perimeter += 1
            
            count += (perimeter + dfs(x - 1, y) + dfs(x + 1, y) + 
                    dfs(x, y - 1) + dfs(x, y + 1))
            
            return count
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    perimeter = dfs(i, j)
        
        return perimeter