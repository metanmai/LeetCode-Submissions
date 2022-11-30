class Solution {
private:
    struct genetic
    {
        string gene;
        bool visited;
    };
    
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string, vector<genetic>> mp;
        queue<string> q;
        int mutations = 0;
        
        for(auto gene : bank)
        {
            string temp = gene;
            for(int i = 0; i < 8; i++)
            {
                temp[i] = '*';
                mp[temp].push_back({gene, false});
                temp[i] = gene[i];
            }
        }
        
        q.push(startGene);
        
        while(!q.empty())
        {
            int len = q.size();
            
            while(len--)
            {
                string currGene = q.front();
                q.pop();
                
                if(currGene == endGene)
                    return mutations;
                
                string temp = currGene;
                
                for(int i = 0; i < 8; i++)
                {
                    temp[i] = '*';
                    
                    for(auto &nextGene : mp[temp])
                    {
                        if(!nextGene.visited)
                        {
                            nextGene.visited = true;
                            q.push(nextGene.gene);
                        }
                    }
                    
                    temp[i] = currGene[i];
                }
            }
            
            
            mutations++;
        }
        
        return -1;
    }
};