class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        first_color = image[sr][sc]
        
        if image[sr][sc] == color:
            return image
        
        visited = set()
        
        def dfs(x, y):
            if (x < 0 or y < 0 or 
                x >= len(image) or y >= len(image[0]) or 
                image[x][y] != first_color):
                return
            
            visited.add((x, y))
            image[x][y] = color
            
            dfs(x + 1, y)
            dfs(x - 1, y)
            dfs(x, y + 1)
            dfs(x, y - 1)
        
        dfs(sr, sc)
        return image