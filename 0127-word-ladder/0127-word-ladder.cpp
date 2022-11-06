class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<pair<string, bool>>> mp; // {word, visited}.
        
        for(string word : wordList)
        {
            string temp = word;
            for(int i = 0; i < word.length(); i++)
            {
                temp[i] = '*';
                mp[temp].push_back({word, false});
                temp[i] = word[i];
            }
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty())
        {
            auto ele = q.front();
            q.pop();
            string word = ele.first, temp = word;
            
            // Check all neighbours for word.
            for(int i = 0; i < word.length(); i++)
            {
                temp[i] = '*';
                for(auto &w : mp[temp])
                {
                    if(w.first == endWord)
                        return ele.second + 1;
                    
                    if(!w.second)
                    {
                        w.second = true;
                        q.push({w.first, ele.second + 1});
                    }
                }
                
                temp[i] = word[i];
            }
        }
        
        return 0;
    }
};