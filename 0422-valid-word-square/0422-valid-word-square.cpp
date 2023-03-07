class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        
        for(auto &str : words)
        {
            if(str.length() > n)
                return false;
            
            str.resize(n, ' ');
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(words[i][j] != words[j][i])
                    return false;
        
        return true;
    }
};