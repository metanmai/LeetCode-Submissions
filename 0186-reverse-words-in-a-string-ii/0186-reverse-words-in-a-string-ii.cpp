class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int lastCharPos = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin() + lastCharPos, s.begin() + i);
                lastCharPos = i + 1;
            }
        }
        
        reverse(s.begin() + lastCharPos, s.end());
    }
};