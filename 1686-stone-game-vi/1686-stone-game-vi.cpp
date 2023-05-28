// https://leetcode.com/problems/stone-game-vi/discuss/969507/C%2B%2B-O(n-log-n)-Optimal-Strategy

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int a = 0, b = 0, n = aliceValues.size();
        vector<vector<int>> vals(n);
        
        for (int i = 0; i < n; i++)
            vals[i] = {aliceValues[i] + bobValues[i], 
                       aliceValues[i], bobValues[i]};
        
        sort(vals.begin(), vals.end(), greater<> ());
        
        for (int i = 0; i < n; i++) 
        {
            a += i % 2 == 1 ? 0 : vals[i][1];
            b += i % 2 == 0 ? 0 : vals[i][2];
        }
        
        return a == b ? 0 : a > b ? 1 : -1;
    }
};