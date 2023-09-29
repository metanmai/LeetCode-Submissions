/* 
Pure Stack + DP Solution.
Time Complexity: O(n)
Space Complexity: O(n)

You can jump from index i to j, if:
1. If nums[i] <= nums[j] and all the values between i and j are lesser than i.
2. If nums[i] > nums[j] and all the values between i and j are greater than or equal to i.
*/

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        stack<int> stk1, stk2;
        vector<long long> total(n, LLONG_MAX);
        total[0] = 0;
        
        stk1.push(0);
        stk2.push(0);

        for(int i = 1; i < n; i++) 
        {
            while(!stk1.empty() and nums[stk1.top()] > nums[i]) 
            {
                total[i] = min(total[i], total[stk1.top()] + costs[i]);
                stk1.pop();
            }
            
            stk1.push(i);
            
            while(!stk2.empty() and nums[stk2.top()] <= nums[i]) 
            {
                total[i] = min(total[i], total[stk2.top()] + costs[i]);
                stk2.pop();
            }
            
            stk2.push(i);
        }
        
        return total.back();
    }
};