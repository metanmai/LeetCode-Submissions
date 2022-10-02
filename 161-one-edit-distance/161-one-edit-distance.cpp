class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        
        if(n > m)
            return isOneEditDistance(t, s); // Switching the parameters so that t is always the smaller one.
        
        if(m - n > 1)
            return false;
        
        for(int i = 0; i < n; i++)
            if(s[i] != t[i])
                return n == m ? s.substr(i + 1) == t.substr(i + 1) : s.substr(i + 1) == t.substr(i);
        
        return m - n == 1;
    }
};