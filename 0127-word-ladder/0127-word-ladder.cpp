class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int transformations = 1;
        map<string, vector<string>> mp;
        set<string> visited;
        queue<string> q;
        
        for(auto word : wordList)
        {
            string temp = word;
            for(int i = 0; i < temp.length(); i++)
            {
                temp[i] = '*';
                mp[temp].push_back(word);
                temp[i] = word[i];
            }
        }
        
        q.push(beginWord);
        
        while(!q.empty())
        {
            int l = q.size();
            
            while(l--)
            {
                auto curr = q.front();
                q.pop();
                string temp = curr;
                
                if(curr == endWord)
                    return transformations;
                
                for(int i = 0; i < curr.length(); i++)
                {
                    temp[i] = '*';
                    
                    for(auto next : mp[temp])
                    {
                        if(visited.count(next))
                            continue;
                        
                        visited.insert(next);
                        q.push(next);
                    }
                    
                    temp[i] = curr[i];
                }
            }
            
            transformations++;
        }
        
        return 0;
    }
};