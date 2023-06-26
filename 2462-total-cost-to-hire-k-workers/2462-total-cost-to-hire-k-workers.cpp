class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long totalCost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {num, leftOrRight}.
        int left = candidates - 1, right = n - candidates;
        
        for(int i = 0; i < candidates; i++)
            pq.push({costs[i], 0});
        
        for(int i = max(candidates, n - candidates); i < n; i++)
            pq.push({costs[i], 1});
        
        while(k--)
        {
            auto [cost, pos] = pq.top(); pq.pop();
            
            totalCost += cost;
            
            if(left < right - 1) // if this condition is false, that means all of the values are already present in the pq. We do this to avoid duplicates.
            {
                if(pos == 0) // left side.
                {
                    left++;
                    pq.push({costs[left], 0});
                }
                
                else // right side.
                {
                    right--;
                    pq.push({costs[right], 1});
                }
            }
        }
        
        return totalCost;
    }
};