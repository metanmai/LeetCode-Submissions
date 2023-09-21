/*
Interview Solution.
Time Complexity: O(sqrt(n))
Space Complexity: O(1)
*/

class Solution {
private:
    long long summation(int n)
    {
        return (long long) n * (n + 1) / 2;
    }
    
public:
    int consecutiveNumbersSum(int n) {
        int totalWays = 0;
        
        for(int i = 1; i <= sqrt(2 * n); i++) // Difference here is this.
        {
            int val = n - summation(i - 1);
            
            if(val > 0 and val % i == 0)
                totalWays++;
        }
        
        return totalWays;
    }
};