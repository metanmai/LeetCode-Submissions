class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> freeServers, takenServers;
        vector<int> answer(m);
        
        for(int i = 0; i < n; i++)
            freeServers.push({servers[i], i});
        
        int currTime = 0;
        
        for(int j = 0; j < m; j++)
        {
            currTime = max(currTime, j);
            
            while(takenServers.size() > 0 and takenServers.top()[0] <= currTime)
            {
                freeServers.push({takenServers.top()[1], takenServers.top()[2]});
                takenServers.pop();
            }
            
            vector<int> server;
            int shift = 0;
            
            if(freeServers.size() > 0)
            {
                server = freeServers.top(); freeServers.pop();
            }
            
            else
            {
                server = takenServers.top(); takenServers.pop();
                shift = 1;
                currTime = server[0];
            }
            
            answer[j] = server[1 + shift];
            takenServers.push({currTime + tasks[j], server[0 + shift], server[1 + shift]});
        }
        
        return answer;
    }
};