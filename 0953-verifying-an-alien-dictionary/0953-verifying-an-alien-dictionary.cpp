class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> pos;
        
        for(int i = 0; i < 26; i++)
            pos[order[i]] = i;
        
        for(int k = 0; k < words.size() - 1; k++)
        {
            string curr = words[k], next = words[k + 1];
            int i = 0, j = 0;
            
            while(i < curr.length() and j < next.length() and 
                  curr[i] == next[i])
                i++, j++;
            
            if(j == next.length())
            {
                if(i < curr.length())
                    return false;
                
                if(i == curr.length())
                    continue;
            }
            
            if(i < curr.length())
                if(pos[curr[i]] > pos[next[j]])
                    return false;
        }
        
        return true;
    }
};