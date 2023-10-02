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
    
    void unionBySize(int node1, int node2)
    {
        int par1 = findParent(node1), par2 = findParent(node2);
        
        if(par1 == par2)
            return;
        
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
    }
};

class Solution {
private:
    vector<int> dirs = {0, 1, 0, -1, 0};
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 1;
        DisjointSet ds(m * n);
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                
                int r1 = i, c1 = j + 1, r2 = i + 1, c2 = j;
                
                if(c1 < n and grid[r1][c1] == 1)
                    ds.unionBySize(n * i + j, n * r1 + c1);
                
                if(r2 < m and grid[r2][c2] == 1)
                    ds.unionBySize(n * i + j, n * r2 + c2);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int area = !grid[i][j];
                set<int> uniqueParents;
                
                for(int k = 0; k < 4; k++)
                {
                    int r = i + dirs[k], c = j + dirs[k + 1];
                    
                    if(min(r, c) < 0 or r >= m or c >= n or grid[r][c] == 0)
                        continue;
                    
                    uniqueParents.insert(ds.findParent(n * r + c));
                }
                
                for(int par : uniqueParents)
                    area += ds.rank[par];
                
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};