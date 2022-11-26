class Solution {
private:
    int findParent(vector<int> parent, int node)
    {
        while(parent[node] != node)
            node = parent[node];
        
        return node;
    }
    
    int performUnion(vector<int> &parent, vector<int> &rank, int node1, int node2)
    {
        int parent1 = findParent(parent, node1), parent2 = findParent(parent, node2);
        
        if(parent1 == parent2)
            return 0;
        
        if(rank[node1] > rank[node2])
        {
            parent[parent2] = parent1;
            rank[node1] += rank[node2];
        }
        
        else
        {
            parent[parent1] = parent2;
            rank[node2] += rank[node1];
        }
        
        return 1;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = n;
        vector<int> parent(n), rank(n, 1);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])
                    provinces -= performUnion(parent, rank, i, j);
        
        return provinces;
    }
};