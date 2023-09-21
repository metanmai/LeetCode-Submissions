/*
Interview Solution.
Time Complexity: O(sqrt(n))
Space Complexity: O(1)
*/

class Solution {
  public:
    int consecutiveNumbersSum(int n) {
        int totalWays = 0, upperLimit = sqrt(2 * n + 0.25) - 0.5;
        
        // Check solution to see why upper bound is this.
        for(int i = 1; i <= upperLimit; i++)
            if((long long) (n - (i * (i - 1) / 2)) % i == 0)
                totalWays++;
        
        return totalWays;
    }
};