class Solution {
public:
    string alienOrder(vector<string>& words) {
        string answer = "";
        map<char, set<char>> adj;
        set<char> characters;
        map<char, int> indegree;
        queue<char> q;
        vector<string> tempWords = {words[0]};
        
        for(int i = 1; i < words.size(); i++)
            if(words[i] != words[i - 1]) // Removing duplicate words, if any.
                tempWords.push_back(words[i]);
        
        words = tempWords;
        int n = words.size();
        
        for(auto word : words)
            for(char ch : word)
                characters.insert(ch); // Getting all the characters in the language.
        
        for(int i = 0; i < n; i++)
        {        
            for(int j = i + 1; j < n; j++)
            {
                int l1 = words[i].length(), l2 = words[j].length();
                int k1 = 0, k2 = 0;
                
                while(k1 < l1 and k2 < l2 and words[i][k1] == words[j][k2])
                    k1++, k2++;
                
                if(k2 == l2)
                    return "";
                
                if(k1 < l1)
                    adj[words[i][k1]].insert(words[j][k2]);
            }
        }
        
        for(auto [currNode, nextNodes] : adj)
            for(auto node : nextNodes)
                indegree[node]++;
            
        
        for(auto character : characters)
            if(indegree[character] == 0)
                q.push(character);
        
        while(!q.empty())
        {
            auto currNode = q.front(); q.pop();
            answer.push_back(currNode);
            
            for(auto nextNode : adj[currNode])
            {
                indegree[nextNode]--;
                
                if(indegree[nextNode] == 0)
                    q.push(nextNode);
            }
        }
        
        return answer.size() == characters.size() ? answer : "";
    }
};