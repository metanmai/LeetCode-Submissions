class DisjointSet
{
private:
    vector<int> parent;
    
public:
    vector<int> rank;
    
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    int unionBySize(int node1, int node2)
    {
        int par1 = findParent(node1), par2 = findParent(node2);
        
        if(par1 == par2)
            return 0;
        
        if(rank[par1] > rank[par2])
        {
            parent[par2] = parent[par1];
            rank[par1] += rank[par2];
        }
        
        else
        {
            parent[par1] = parent[par2];
            rank[par2] += rank[par1];
        }
        
        return 1;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), components = n;
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(stones[i][0] == stones[j][0] or 
                   stones[i][1] == stones[j][1])
                    components -= ds.unionBySize(i, j);
        
        return n - components;
    }
};