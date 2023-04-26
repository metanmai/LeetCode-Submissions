class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
        {
            int nn = num, sum = 0;
            
            while(nn)
            {
                int rem = nn % 10;
                nn /= 10;
                sum += rem;
            }
            
            num = sum;
        }
        
        return num;
    }
};