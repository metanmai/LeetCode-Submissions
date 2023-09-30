#define MAXI numeric_limits<int>::max()

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> curr(n), next(n, MAXI);
        
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                int right = MAXI, down = MAXI;
                
                if(j + 1 != n)
                    right = max(1, curr[j + 1] - dungeon[i][j]);
                
                if(i + 1 != m)
                    down = max(1, next[j] - dungeon[i][j]);
                
                int currHealth = min(right, down);
                
                if(currHealth != MAXI)
                    curr[j] = currHealth;
                
                else
                    curr[j] = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
            }
            
            next = curr;
        }
        
        return curr[0];
    }
};