class Solution {
public:
    int longestPalindrome(string s) {
        int a[52], is_odd_present = 0, count = 0;
        for(int i = 0; i < 52; i++)
            a[i] = 0;
        
        for(int i = 0; i < s.length(); i++)
            if(isupper(s[i]))
                a[s[i] - 'A' + 26]++;
            else
                a[s[i] - 'a']++;
        
        for(int i = 0; i < 52; i++)
            if(a[i] % 2 == 0)
                count += a[i];
            else
            {
                is_odd_present = 1;
                count += a[i] - 1;
            }

        return count + is_odd_present;
    }
};