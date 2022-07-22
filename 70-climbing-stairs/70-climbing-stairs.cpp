class Solution {
public:
    int climbStairs(int n) {
        int t1 = 1, t2 = 2, t3;
        for(int i = 0; i < n - 2; i++)
        {
            t3 = t1 + t2;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};