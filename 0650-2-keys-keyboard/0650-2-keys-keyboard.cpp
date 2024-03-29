class Solution {
public:
    int minSteps(int n) {
        int answer = 0, d = 2;
        
        while(n > 1) 
        {
            while(n % d == 0) 
                answer += d, n /= d;
            
            d++;
        }
        
        return answer;
    }
};