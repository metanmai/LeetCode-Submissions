class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        long long maxPerf = 1;
        
        vector<pair<int, int>> perf;
        
        for(int i = 0; i < n; i++)
            perf.push_back({efficiency[i], speed[i]});
        
        sort(perf.begin(), perf.end(), greater<> ());
        
        priority_queue<int, vector<int>, greater<>> pq;
        long long currSum = 0;

        for(int i = 0; i < n; i++)
        {
            maxPerf = max(maxPerf, 
                          (perf[i].first * (currSum = currSum + perf[i].second)));

            pq.push(perf[i].second);
            
            if(pq.size() == k)
            {
                currSum -= pq.top();
                pq.pop();
            }
        }
        
        return maxPerf % MOD;
    }
};