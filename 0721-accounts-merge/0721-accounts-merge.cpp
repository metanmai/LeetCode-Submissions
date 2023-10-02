class DisjointSet
{
private:
    vector<int> parent, rank;
    
public:
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> answer, emails(n);
        DisjointSet ds(n);
        map<string, int> mailNodeMap;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                if(!mailNodeMap.count(accounts[i][j]))
                    mailNodeMap[accounts[i][j]] = i;
                
                ds.unionBySize(i, mailNodeMap[accounts[i][j]]);
            }
        }
        
        for(auto [mail, node] : mailNodeMap)
            emails[ds.findParent(node)].push_back(mail);
        
        for(int i = 0; i < n; i++)
        {
            if(emails[i].size() == 0)
                continue;
            
            sort(emails[i].begin(), emails[i].end());
            vector<string> person = {accounts[i][0]};
            person.insert(person.end(), emails[i].begin(), emails[i].end());
            
            answer.push_back(person);
        }
        
        return answer;
    }
};