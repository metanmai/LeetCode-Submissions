class Solution {
private:
    struct word
    {
        string w;
        bool visited;
    };

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int transformations = 1;
        map<string, vector<word>> mp;
        queue<string> q;
        
        // Making a map of all possible patterns.
        for(auto word : wordList)
        {
            string temp = word;
            for(int i = 0; i < temp.length(); i++)
            {
                temp[i] = '*';
                mp[temp].push_back({word, false});
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
                
                // Check all neighbours of curr.
                for(int i = 0; i < curr.length(); i++)
                {
                    temp[i] = '*';
                    
                    for(auto &next : mp[temp])
                    {
                        if(!next.visited)
                        {
                            next.visited = true;
                            q.push(next.w);
                        }
                    }
                    
                    temp[i] = curr[i];
                }
            }
            
            transformations++;
        }
        
        return 0;
    }
};