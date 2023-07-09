class Solution {
public:
    int largestVariance(string s) {
        vector<int> counter(26);
        for (char ch : s)
            counter[ch - 'a']++;
        
        int globalMax = 0;
        
        for (int i = 0; i < 26; i++) 
        {
            for (int j = 0; j < 26; j++) 
            {
                if (i == j or counter[i] == 0 or counter[j] == 0)
                    continue;
                       
                char major = 'a' + i, minor = 'a' + j;
                int majorCount = 0, minorCount = 0;
                
                int restMinor = counter[j];
                
                for (char ch : s) 
                {    
                    if (ch == major)
                        majorCount++;
                    
                    if (ch == minor) 
                        minorCount++, restMinor--;
                    
                    if (minorCount > 0)
                        globalMax = max(globalMax, majorCount - minorCount);
                    
                    if (majorCount < minorCount and restMinor > 0) 
                        majorCount = 0, minorCount = 0;
                }
            }
        }
        
        return globalMax;
    }
};
