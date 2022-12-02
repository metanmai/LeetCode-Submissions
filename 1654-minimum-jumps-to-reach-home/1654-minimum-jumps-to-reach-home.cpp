class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int minJumps = 0;
        vector<vector<int>> visited(6001, vector<int> (2, -1)); // {position, canJumpBack}.
        queue<vector<int>> q;
        q.push({0, 0});
        
        for(int num : forbidden)
            visited[num][0] = visited[num][1] = 1;
        
        while(!q.empty())
        {
            int l = q.size();
            
            while(l--)
            {
                auto curr = q.front();
                q.pop();
                
                int currPos = curr[0], jumpedBack = curr[1];
                
                if(currPos == x)
                    return minJumps;
                
                if(currPos < 0 or currPos >= 6000 or 
                   visited[currPos][!jumpedBack] != -1)
                    continue;
                
                visited[currPos][!jumpedBack] = 1;
                
                q.push({currPos + a, 0});
                
                if(!jumpedBack)
                    q.push({currPos - b, 1});
            }
            
            minJumps++;
        }
        
        return -1;
    }
};