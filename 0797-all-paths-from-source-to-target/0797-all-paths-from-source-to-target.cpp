class Solution {
private:
    void findPaths(vector<vector<int>>& graph, vector<vector<int>> &paths, vector<bool> &visited,
                   vector<int> currPath, int pos, int n)
    {
        if(pos == n - 1)
        {
            paths.push_back(currPath);
            return;
        }
        
        visited[pos] = true;
        for(int i = 0; i < graph[pos].size(); i++)
        {
            currPath.push_back(graph[pos][i]);
            findPaths(graph, paths, visited, currPath, graph[pos][i], n);
            currPath.pop_back();
        }
        visited[pos] = false;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n);
        vector<int> currPath;
        vector<vector<int>> paths;
        
        findPaths(graph, paths, visited, {0}, 0, n);
        return paths;
    }
};