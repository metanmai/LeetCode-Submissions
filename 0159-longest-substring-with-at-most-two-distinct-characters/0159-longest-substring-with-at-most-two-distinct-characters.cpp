class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {        
        map<char, int> freq;
        int i = 0, maxLen = 1, alphs = 0;
        
        for(int j = 0; j < s.length(); j++)
        {
            if(freq.find(s[j]) != freq.end())
                freq[s[j]]++;

            else if(freq.size() < 2)
                freq[s[j]] = 1;
            
            else
            {
                while(true)
                {
                    freq[s[i]]--;
                    
                    if(freq[s[i]] == 0)
                    {
                        freq.erase(s[i++]);
                        break;
                    }
                    
                    i++;
                }
                
                freq[s[j]] = 1;
            }
            
            maxLen = max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
};