class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int minDist = INT_MAX, prevWord = 0, prevIndex = -1;
        
        for(int i = 0; i < wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1 and prevWord == 2 or
               wordsDict[i] == word2 and prevWord == 1)
                minDist = min(minDist, i - prevIndex);
               
            if(wordsDict[i] == word1 or wordsDict[i] == word2)
            {
                if(wordsDict[i] == word1)
                    prevWord = 1;
                
                else
                    prevWord = 2;
                
                prevIndex = i;
            }
               
        }
        
        return minDist;
    }
};