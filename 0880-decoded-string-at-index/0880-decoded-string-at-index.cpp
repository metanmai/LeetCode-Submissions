class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long len = 0;

        // Find length of decoded string
        for (int i = 0; i < n; i++)
            len = (s[i] >= '1' and s[i] <= '9') ? len * (s[i] - '0') : len + 1;

        for (int i = n - 1; i >= 0; i--) 
        {
            k %= len;
            
            if (k == 0 and isalpha(s[i]))
                return (string) "" + s[i];

            len = (s[i] >= '1' and s[i] <= '9') ? len / (s[i] - '0') : len - 1;
        }
        
        return "";
    }
};