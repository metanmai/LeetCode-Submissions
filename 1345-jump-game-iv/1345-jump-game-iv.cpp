class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        map<int, vector<int>> indices;
        queue<pair<int, int>> q;
        vector<bool> visitedIdx(n);
        set<int> visitedEles;
        
        for(int i = 0; i < n; i++)
            indices[arr[i]].push_back(i);
        
        q.push({0, 0});
        
        while(!q.empty())
        {
            auto [pos, jumps] = q.front(); q.pop();
            
            if(pos == n - 1)
                return jumps;
            
            if(visitedIdx[pos])
                continue;
            
            visitedIdx[pos] = true;
            
            if(pos > 0)
                q.push({pos - 1, jumps + 1});
            
            if(pos < n - 1)
                q.push({pos + 1, jumps + 1});
            
            if(visitedEles.find(arr[pos]) == visitedEles.end())
                for(int next : indices[arr[pos]])
                    q.push({next, jumps + 1});
            
            visitedEles.insert(arr[pos]);
        }
        
        return n - 1;
    }
};