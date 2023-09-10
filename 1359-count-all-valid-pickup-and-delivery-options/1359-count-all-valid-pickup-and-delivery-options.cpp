/* 
This math solution is neat. Why didn't you think of this?
Ways to arrange pickups is your usual n!, so just multiply with i on each step.
Ways to arrange deliveries follows the pattern: 1, 3, 5, 7, ... 2n - 1. 
*/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countOrders(int n) {
        int MOD = 1e9 + 7;
        long long answer = 1;
        
        for(int i = 1; i <= n; i++)
            answer = ((answer % MOD) * ((i * (2 * i - 1)) % MOD)) % MOD;
        
        return answer;
    }
};