/* 
Here, The catch is to use a visited vector which not only keeps track of whether
or not a node has been visited, but also checks whether or not it was visited 
with a particular state. 
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), finalMask = (1 << n) - 1, minPath = 0;
        vector<vector<bool>> visited(n, vector<bool> (finalMask + 1));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
            q.push({i, 1 << i});
        
        while(!q.empty())
        {
            minPath++;
            int len = q.size();
            
            while(len--)
            {
                auto [currNode, currMask] = q.front(); q.pop();
                
                for(int nextNode : graph[currNode])
                {
                    int nextMask = currMask | (1 << nextNode);
                    
                    if(nextMask == finalMask)
                        return minPath;
                    
                    if(visited[nextNode][nextMask])
                        continue;
                    
                    visited[nextNode][nextMask] = true;
                    
                    q.push({nextNode, nextMask});
                }
            }
        }
        
        return 0;
    }
};