class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int pals = 0;

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            int i = 0, j = s.length() - 1;
            
            while(i <= j and s[i] != ch)
                i++;
            
            while(i <= j and s[j] != ch)
                j--;
            
            set<char> unique;
            
            for(int k = i + 1; k < j; k++)
                unique.insert(s[k]);
            
            pals += unique.size();
        }
        
        return pals;
    }
};