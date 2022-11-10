class Solution {
public:
    int numberBreak(int n, vector<int> &breaks)
    {
        if(breaks[n] != -1)
            return breaks[n];
        
        int maxProd = n - 1;
        
        for(int i = 1; i < n; i++)
            maxProd = max(maxProd, max(i * numberBreak(n - i, breaks), i * (n - i)));
        
        return breaks[n] = maxProd;
    }
    
    int integerBreak(int n) {
        vector<int> breaks(n + 1, -1);
        return numberBreak(n, breaks);
    }
};