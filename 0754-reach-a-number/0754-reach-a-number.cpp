// https://leetcode.com/problems/reach-a-number/discuss/188999/Throw-Out-All-Fucking-Explanations-This-is-nice-explanation-(c%2B%2B)-I-think-.......

/* 
Basically find the first number k such that k * (k + 1) / 2 >= target.
If the summation 1 to k is equal to target, or the difference between the summation and 
the target is an even number, then k is the minimum number of steps.
*/

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int steps = 0, sum = 0;
        
        while(true)
        {
            sum += ++steps;
            
            if(sum == target or
               (sum > target and (sum - target) % 2 == 0))
                return steps;
        }
    
        return -1;
    }
};