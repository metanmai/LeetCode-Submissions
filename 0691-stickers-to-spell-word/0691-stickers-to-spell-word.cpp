class Solution {
private:
    int findMinStickers(unordered_map<string, int> &dp, vector<vector<int>> &stkrFreqs, string &target, int n)
    {
        if(target == "")
            return 0;
        
        if(dp.find(target) != dp.end())
            return dp[target];
        
        int minStickers = 1e9;
        
        for(auto tempStick : stkrFreqs)
        {
            string notFound = "";
            
            for(char &ch : target)
            {
                if(tempStick[ch - 'a'] > 0)
                    tempStick[ch - 'a']--;
                
                else
                    notFound.push_back(ch);
            }
            
            if(notFound == target)
                continue;
            
            int nextStickers = findMinStickers(dp, stkrFreqs, notFound, n);
            minStickers = min(minStickers, 1 + nextStickers);
        }
        
        return dp[target] = minStickers;
    }
    
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> stkrFreqs;
        unordered_map<string, int> dp;
        
        for(auto &sticker : stickers)
        {
            vector<int> currStkr(26);
            
            for(char ch : sticker)
                currStkr[ch - 'a']++;
            
            stkrFreqs.push_back(currStkr);
        }
        
        int answer = findMinStickers(dp, stkrFreqs, target, n);
        
        return answer == 1e9 ? -1 : answer;
    }
};