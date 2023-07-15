class Solution {
public:
    int trailingZeroes(int n) {
        int nn = n;
        int fives = 0;
        
        for(int i = 5; i <= n; i += 5)
        {
            int count = 0, num = i;
            
            while(num % 5 == 0)
                num /= 5, count++;
            
            fives += count;
        }
        
        return fives;
    }
};