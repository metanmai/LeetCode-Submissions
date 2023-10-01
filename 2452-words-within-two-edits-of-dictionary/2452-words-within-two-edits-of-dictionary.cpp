class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> answer;
        unordered_set<string> patterns;
        
        for(auto word : dictionary)
        {
            string temp = word;
            
            for(int i = 0; i < word.size(); i++)
            {
                temp[i] = '*';
                patterns.insert(temp);
                
                for(int j = i + 1; j < word.size(); j++)
                {
                    temp[j] = '*';
                    patterns.insert(temp);
                    temp[j] = word[j];
                }
                
                temp[i] = word[i];
            }
        }
        
        for(auto word : queries)
        {
            string temp = word;
            bool foundPattern = false;
            
            for(int i = 0; i < word.size(); i++)
            {
                temp[i] = '*';
                
                if(patterns.count(temp) and !foundPattern)
                    foundPattern = true;
                
                if(foundPattern)
                    break;
                
                for(int j = i + 1; j < word.size(); j++)
                {
                    temp[j] = '*';
                    
                    if(patterns.count(temp) and !foundPattern)
                        foundPattern = true;
                    
                    temp[j] = word[j];
                }
                
                temp[i] = word[i];
            }
            
            if(foundPattern)
                answer.push_back(word);
        }
        
        return answer;
    }
};