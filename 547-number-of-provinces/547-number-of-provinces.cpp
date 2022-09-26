class Solution {
public:
    int find(int node, vector<int> parent)
    {
        while(node != parent[node])
            node = parent[node];
        
        return node;
    }
    
    int unionize(int node1, int node2, vector<int> &parent, vector<int> &rank)
    {
        int parent1 = find(node1, parent), parent2 = find(node2, parent);
        
        if(parent1 == parent2)
            return 0;
        
        if(rank[parent1] > rank[parent2])
        {
            parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        }
        
        else
        {
            parent[parent1] = parent2;
            rank[parent2] += rank[parent2];
        }
        
        return 1;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n, 1);
        int provinces = n;
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])
                    provinces -= unionize(i, j, parent, rank);
        
        return provinces;
    }
};