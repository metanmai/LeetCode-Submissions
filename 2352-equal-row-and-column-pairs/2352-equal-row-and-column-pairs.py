class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        count = 0
        
        def column(j):
            col =[i[j] for i in grid]
            return col
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i] == column(j):
                    count += 1
                    
        return count
            