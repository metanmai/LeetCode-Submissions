class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), maxString = 0;
        int i = 0, maxFreq = 0;
        map<int, int> freq;
        
        for(int j = 0; j < n; j++)
        {
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            
            while(j - i + 1 - maxFreq > k)
                freq[s[i]]--, i++;
            
            maxString = max(maxString, j - i + 1);
        }
        
        return maxString;
    }
};