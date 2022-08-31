class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        answer = []
        r, c = len(heights), len(heights[0])

        def canFlowPacific(x1, y1, x2, y2, visited):       
            if x2 < 0 or y2 < 0 :
                return True
            
            elif ((x2, y2) in visited or 
                  x2 >= r or y2 >= c or 
                  heights[x1][y1] < heights[x2][y2]):
                return False
            
            visited.add((x2, y2))
            if [x2, y2] in answer:
                return True
            
            return (canFlowPacific(x2, y2, x2 - 1, y2, visited) or
                    canFlowPacific(x2, y2, x2, y2 - 1, visited) or
                    canFlowPacific(x2, y2, x2 + 1, y2, visited) or
                    canFlowPacific(x2, y2, x2, y2 + 1, visited))
                    
                
        def canFlowAtlantic(x1, y1, x2, y2, visited):
            if x2 >= r or y2 >= c:
                return True
            
            elif ((x2, y2) in visited or 
                  x2 < 0 or y2 < 0 or 
                  heights[x1][y1] < heights[x2][y2]):
                return False
            
            visited.add((x2, y2))
            if [x2, y2] in answer:
                return True
            
            return (canFlowAtlantic(x2, y2, x2 - 1, y2, visited) or
                    canFlowAtlantic(x2, y2, x2, y2 - 1, visited) or
                    canFlowAtlantic(x2, y2, x2 + 1, y2, visited) or
                    canFlowAtlantic(x2, y2, x2, y2 + 1, visited))
        
        for i in range(r):
            for j in range(c):
                if (canFlowPacific(i, j, i, j, set()) and
                    canFlowAtlantic(i, j, i, j, set())):
                    answer.append([i, j])
        
        return answer