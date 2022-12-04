class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        visited = [-1] * n
        
        def minCost(pos):
            if pos >= n:
                return 0
            
            if visited[pos] != -1:
                return visited[pos]
            
            visited[pos] = cost[pos] + min(minCost(pos + 1), minCost(pos + 2))
            return visited[pos]
        
        return min(minCost(0), minCost(1))