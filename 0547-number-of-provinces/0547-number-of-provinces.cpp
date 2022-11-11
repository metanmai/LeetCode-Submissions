class Solution {
public:
    int find(vector<int> parent, int node)
    {
        while(parent[node] != node)
            node = parent[node];
        
        return node;
    }
    
    int unionize(vector<int> &parent, vector<int> &rank, int node1, int node2)
    {
        int parent1 = find(parent, node1), parent2 = find(parent, node2);
        if(parent1 == parent2)
            return 0;
        
        if(rank[parent1] > rank[parent2])
        {
            parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        }
        
        else
        {
            parent[parent1]  = parent2;
            rank[parent2] += rank[parent1];
        }
        
        return 1;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = n;
        vector<int> parent, rank(n, 1);
        
        for(int i = 0; i < n; i++)
            parent.push_back(i);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])
                    provinces -= unionize(parent, rank, i, j);
        
        return provinces;
    }
};