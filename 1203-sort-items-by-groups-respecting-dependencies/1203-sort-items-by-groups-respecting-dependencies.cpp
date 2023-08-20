class Solution {
private:
    vector<int> topoSort(map<int, vector<int>> &adj, vector<int> &indegree)
    {
        queue<int> q;
        vector<int> sorted;
        
        for(int i = 0; i < indegree.size(); i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            auto currNode = q.front(); q.pop();
            
            sorted.push_back(currNode);
            
            for(auto nextNode : adj[currNode])
                if(--indegree[nextNode] == 0)
                    q.push(nextNode);
        }
        
        return sorted;
    }
    
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupNumber = m;
        vector<int> orderedItems, orderedGroups, answer;
        map<int, vector<int>> items, groups, myGroups;
        queue<int> q;
        
        /* 
        All non-grouped items will be considered as it's own group. Kinda like Australia
        (because Australia is isolated from the rest of the world. So it became it's own continent).
        */
        
        for(int i = 0; i < n; i++)
            if(group[i] == -1)
                group[i] = groupNumber++; 
        
        vector<int> itemIndegree(n), groupIndegree(groupNumber);
        
        for( int i = 0; i < n; i++)
        {
            for(int item : beforeItems[i])
            {
                itemIndegree[i]++;
                items[item].push_back(i);
                
                /* 
                If 'i' and 'item' are not from the the same group, that means that the group of 'item' 
                has to come before the group of 'i'. So we create a seperate graph with 
                the group dependencies, and we topologically sort that. 
                */
                if(group[i] != group[item]) 
                {
                    groupIndegree[group[i]]++;
                    groups[group[item]].push_back(group[i]);
                }
            }
        }
        
        orderedItems = topoSort(items, itemIndegree);
        orderedGroups = topoSort(groups, groupIndegree);
        
        if(orderedItems.size() != n or orderedGroups.size() != groupNumber)
            return {};
        
        for(int item : orderedItems)
            myGroups[group[item]].push_back(item);
        
        for(int grp : orderedGroups)
            answer.insert(answer.end(), myGroups[grp].begin(), myGroups[grp].end());
        
        return answer;
    }
};