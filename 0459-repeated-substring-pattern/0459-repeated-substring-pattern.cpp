class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        for(int i = 1; i <= n / 2; i++)
        {
            int j = 0;
            string pattern = s.substr(0, i);
            
            while(s.substr(j, i) == pattern)
                j += i;
            
            if(j == n)
                return true;
        }
        
        return false;
    }
};