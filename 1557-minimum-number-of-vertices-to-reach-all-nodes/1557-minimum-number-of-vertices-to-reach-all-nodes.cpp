class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        /* 
        Just return all the nodes which have indegree = 0, because :
        - Nodes with indegree 0 cannot be reached from any other node, so they must be in the answer.
        - Every other node can be reached from some other node. 
        */
        
        vector<int> indegree(n), answer;
        
        for(auto edge : edges)
            indegree[edge[1]]++;
        
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                answer.push_back(i);
        
        return answer;
    }
};