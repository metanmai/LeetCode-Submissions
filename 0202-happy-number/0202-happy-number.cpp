class Solution {
public:
    int happyCalc(int n)
    {
        int sum = 0;
        while(n > 0)
            sum += pow(n % 10, 2), n /= 10;
        
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        
        do slow = happyCalc(slow), fast = happyCalc(happyCalc(fast)); while(slow != fast);
        
        return slow == 1;
    }
};