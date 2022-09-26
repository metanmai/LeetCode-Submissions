class Solution {
public:
    int find(int node, vector<int> &parent)
    {
        while(node != parent[node])
            node = parent[node];
        
        return node;
    }
    
    int unionize(int node1, int node2, vector<int> &parent, vector<int> &rank)
    {
        int parent1 = find(node1, parent), parent2 = find(node2, parent);
        
        if(parent1 == parent2)
            return 0; // No union is performed, so number of components doesn't decrease.
        
        if(rank[parent1] > rank[parent2])
        {
            parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        }
        
        else
        {
            parent[parent1] = parent2;
            rank[parent2] += rank[parent1];
        }
        
        return 1; // Union is performed, so number of components decreases by 1.
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 1);
        int components = n;
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(auto edge : edges)
            components -= unionize(edge[0], edge[1], parent, rank);
        
        return components;
    }
};