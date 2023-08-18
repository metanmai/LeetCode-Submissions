class Solution {
private:
    double getMinDistance(map<string, map<string, double>> &paths, vector<string> &query)
    {
        string a = query[0], b = query[1];
        
        if(!paths.count(a) or !paths.count(b))
            return -1;
        
        queue<pair<string, double>> q; // {variable, product}.
        set<string> visited;
        q.push({a, 1.0});
        
        while(!q.empty())
        {
            auto [currNode, currVal] = q.front(); q.pop();
            
            if(currNode == b)
                return currVal;
            
            visited.insert(currNode);
            
            for(auto [nextNode, nextVal] : paths[currNode])
                if(!visited.count(nextNode))
                    q.push({nextNode, currVal * nextVal});
        }
        
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        map<string, map<string, double>> paths;
        vector<double> answer;
        
        for(int i = 0; i < n; i++)
        {
            paths[equations[i][0]][equations[i][1]] = values[i];
            paths[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        
        for(auto query : queries)
            answer.push_back(getMinDistance(paths, query));
        
        return answer;
    }
};