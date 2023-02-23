#define ff first
#define ss second

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> maxProfits;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minCapital;
        
        for(int i = 0; i < n; i++)
            minCapital.push({capital[i], profits[i]});
        
        for(int i = 1; i <= k; i++)
        {
            while(!minCapital.empty() and  minCapital.top().ff <= w)
            {
                maxProfits.push(minCapital.top().ss);
                minCapital.pop();
            }
            
            if(!maxProfits.empty())
            {
                w += maxProfits.top();
                maxProfits.pop();
            }
        }
        
        return w;
    }
};