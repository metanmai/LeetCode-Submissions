class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        int n = jobs.size(), mostTime = 0;
        sort(jobs.begin(), jobs.end());
        sort(workers.begin(), workers.end());
        
        for(int i = 0; i < n; i++)
            mostTime = max(mostTime, (int) ceil((float) jobs[i] / workers[i]));
        
        return mostTime;
    }
};