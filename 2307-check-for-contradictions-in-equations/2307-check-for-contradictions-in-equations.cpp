class Solution {
private:
    bool isValidEquation(map<string, map<string, double>> &paths, vector<string> &equation, double value)
    {
        string a = equation[0], b = equation[1];
        set<string> visited;
        queue<pair<string, double>> q;
        
        q.push({a, 1});
        
        while(!q.empty())
        {
            auto [currNode, currVal] = q.front(); q.pop();
            
            if(currNode == b)
                return currVal == value;
            
            visited.insert(currNode);
            
            for(auto [nextNode, nextVal] : paths[currNode])
                if(!visited.count(nextNode))
                    q.push({nextNode, currVal * nextVal});
        }
        
        return true;
    }
    
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        int n = values.size();
        map<string, map<string, double>> paths;
        
        for(int i = 0; i < n; i++)
        {
            if(isValidEquation(paths, equations[i], values[i]))
            {
                paths[equations[i][0]][equations[i][1]] = values[i];
                paths[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            }
            
            else
                return true;
        }
        
        return false;
    }
};