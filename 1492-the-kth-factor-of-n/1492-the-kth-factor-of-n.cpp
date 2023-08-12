class Solution {
public:
    int kthFactor(int n, int k) {
        int factors = 0;
        
        for(int i = 1; i <= n; i++)
            if(n % i == 0)
            {
                factors++;
                
                if(factors == k)
                    return i;
            }
        
        return -1;
    }
};