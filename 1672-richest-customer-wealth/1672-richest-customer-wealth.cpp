class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        
        for(auto acc : accounts)
            richest = max(richest, accumulate(acc.begin(), acc.end(), 0));
        
        return richest;
    }
};