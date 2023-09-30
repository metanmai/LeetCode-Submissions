/*
Greedy Solution.
Time Complexity: O(n + m)
Space Complexity: O(1)

We MUST go through every single row between startPos[0] and homePos[0] as well as every column between 
startPos[1] and homePos[1]. So, we just need to add them up.
*/

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        int dr = startPos[0] > homePos[0] ? -1 : 1, dc = startPos[1] > homePos[1] ? -1 : 1;
        
        for(int r = startPos[0]; r != homePos[0]; r += dr)
            cost += rowCosts[r + dr];
        
        for(int c = startPos[1]; c != homePos[1]; c += dc)
            cost += colCosts[c + dc];
        
        return cost;
    }
};