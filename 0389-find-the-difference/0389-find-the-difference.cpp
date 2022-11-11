class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26], b[26];
        for(int i = 0; i < 26; i++)
            a[i] = b[i] = 0;
        
        for(char c : s)
            a[c - 'a']++;
        
        for(char c : t)
            b[c - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(a[i] != b[i])
                return char(i + 'a');
        
        return ' ';
    }
};