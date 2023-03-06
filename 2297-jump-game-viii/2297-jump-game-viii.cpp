/* You can jump from index i to j, if:
1. If nums[i] <= nums[j] and all the values between i and j are lesser than i.
2. If nums[i] > nums[j] and all the values between i and j are greater than or equal to i.
*/

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        stack<int> stk;
        vector<long long> minCost(n, LLONG_MAX);
        vector<vector<int>> adj(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        minCost[0] = 0;
        
        // Next greater element.
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() and nums[i] >= nums[stk.top()])
            {
                adj[stk.top()].push_back(i);
                stk.pop();
            }
            
            stk.push(i);
        }
        
        stk = stack<int>{};
        
        // Next smaller element.
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() and nums[i] < nums[stk.top()])
            {
                adj[stk.top()].push_back(i);
                stk.pop();
            }
            
            stk.push(i);
        }
        
        // Dijkstra's algorithm.
        while(!pq.empty())
        {
            auto [currCost, currEle] = pq.top(); pq.pop();
            
            for(int nextEle : adj[currEle])
                if(costs[nextEle] + currCost < minCost[nextEle])
                    pq.push({minCost[nextEle] = costs[nextEle] + currCost, nextEle});
        }
        
        return minCost.back();
    }
};