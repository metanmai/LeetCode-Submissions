class Solution {
public:
    int firstUniqChar(string s) {
        int a[26];
        for(int i = 0; i < 26; i++)
            a[i] = 0;
        for(int i = 0; i < s.length(); i++)
            a[(int) s[i] - 97] += 1;
        
        for(int i = 0; i < s.length(); i++)
            if(a[(int) s[i] - 97] == 1)
                return i;
        
        return -1;
    }
};