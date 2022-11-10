class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<int> minSquares(n + 1, 4); // Lagrange's four-square theorem.
        minSquares[0] = 0;
        int sq = 1;
        
        while(sq * sq <= n)
        {
            squares.push_back(sq * sq);
            minSquares[sq * sq] = 1;
            sq++;
        }
        
        for(int i = 1; i <= n; i++)
            for(int sq : squares)
                if(i > sq)
                    minSquares[i] = min(minSquares[i], minSquares[i - sq] + 1);
        
        return minSquares[n];
    }
};