class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        int n = s.length(), i = 0, j = 0;
        vector<char> mismatch;
        vector<int> freq(26);
        bool swapped = false;
        
        for(int i = 0, j = 0; i < n, j < n; i++, j++)
        {
            if(s[i] == goal[i])
                continue;
            
            if(swapped)
                return false;
            
            if(mismatch.size() == 0)
                mismatch = {s[i], goal[i]};
            
            else if(s[i] == mismatch[1] and goal[i] == mismatch[0])
                swapped = true;
            
            else
                return false;
        }
        
        if(mismatch.size() and !swapped)
            return false;
        
        else if(swapped)
            return true;
        
        for(char ch : s)
        {
            if(freq[ch - 'a'] == 1)
                return true;

            freq[ch - 'a']++;
        }
        
        return false;
    }
};