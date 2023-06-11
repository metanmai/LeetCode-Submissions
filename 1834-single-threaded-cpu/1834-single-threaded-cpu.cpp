#define ll long long

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> answer;
        priority_queue<vector<ll>, vector<vector<ll>>, greater<>> remTasks, availableTasks;
        
        for(int i = 0; i < n; i++)
            remTasks.push({tasks[i][0], tasks[i][1], i}); // {enqueueTime, processingTime, taskNum}.
        
        ll currTime = 0;
        
        while(!remTasks.empty() or !availableTasks.empty())
        {
            if(availableTasks.size() == 0)
                currTime = max(currTime, remTasks.top()[0]);
            
            while(!remTasks.empty() and remTasks.top()[0] <= currTime)
            {
                auto curr = remTasks.top(); remTasks.pop();
                availableTasks.push({curr[1], curr[2]});
            }
            
            auto currTask = availableTasks.top(); availableTasks.pop();
            currTime += currTask[0];
            answer.push_back(currTask[1]);
        }
        
        return answer;
    }
};