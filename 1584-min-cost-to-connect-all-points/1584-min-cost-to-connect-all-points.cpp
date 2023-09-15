// Kruskal's Algorithm.

#define ff first
#define ss second

class DisjointSet
{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int node1, int node2)
    {
        int par1 = findParent(node1), par2 = findParent(node2);

        if(par1 != par2)
        {
            if(rank[par1] < rank[par2])
            {
                parent[par1] = par2;
                rank[par2] += rank[par1];
            }

            else
            {
                parent[par2] = par1;
                rank[par1] += rank[par2];
            }

            return true;
        }

        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), cost = 0;
        DisjointSet ds(n);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater <>> pq; // {distance, {node1, node2}}.

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                pq.push({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
        
        while(!pq.empty())
        {
            auto top = pq.top(); pq.pop();
            if(ds.unionBySize(top.ss.ff, top.ss.ss))
                cost += top.ff;
        }

        return cost;
    }
};