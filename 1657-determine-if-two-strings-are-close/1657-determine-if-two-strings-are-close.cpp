// Check if the two strings have the same characters and the same frequencies.

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();

        if(l1 != l2)
            return false;
        
        vector<int> freq1(26), freq2(26), freqFreqs1(l1 + 1), freqFreqs2(l1 + 1);

        for(int i = 0; i < l1; i++)
            freq1[word1[i] - 'a']++, freq2[word2[i] - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(freq1[i] == 0 xor freq2[i] == 0)
                return false;
        
        for(int i = 0; i < 26; i++)
            freqFreqs1[freq1[i]]++, freqFreqs2[freq2[i]]++;
        
        return freqFreqs1 == freqFreqs2;
    }
};