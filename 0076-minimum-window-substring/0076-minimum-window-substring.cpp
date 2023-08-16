class Solution {
private:
    void changeChar(vector<int> &freq, char ch, int val)
    {
        if(ch >= 'a' and ch <= 'z')
            freq[ch - 'a'] += val;
        
        else
            freq[ch - 'A' + 26] += val;
    }
    
    bool checkFreqs(vector<int> &sFreqs, vector<int> &tFreqs)
    {
        for(int i = 0; i < 52; i++)
            if(tFreqs[i] > sFreqs[i])
                return false;
        
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        int n = s.length(), minWindowStr = INT_MAX;
        int windowStart = -1;
        string answer = "";
        vector<int> sFreqs(52), tFreqs(52);
        
        for(char ch : t)
            changeChar(tFreqs, ch, 1);
        
        int i = 0;
        
        for(int j = 0; j < n; j++)
        {
            changeChar(sFreqs, s[j], 1);
            
            while(i <= j and checkFreqs(sFreqs, tFreqs))
            {
                if(j - i + 1 < minWindowStr)
                    windowStart = i, minWindowStr = j - i + 1;
                
                changeChar(sFreqs, s[i], -1);
                i++;
            }
        }
        
        return minWindowStr != INT_MAX ? s.substr(windowStart, minWindowStr) : "";
    }
};