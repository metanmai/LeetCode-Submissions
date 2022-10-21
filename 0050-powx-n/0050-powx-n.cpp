class Solution {
public:
    double myPow(double x, long n) {
        long nn = abs(n);
        double ans = 1;
        
        while(nn > 0) // log n operation.
        {
            if(nn % 2 == 0)
            {
                x *= x;
                nn /= 2;
            }
            else
            {
                ans *= x;
                nn--;
            }
        }
        
        return n > 0 ? ans : (1 / ans);
    }
};