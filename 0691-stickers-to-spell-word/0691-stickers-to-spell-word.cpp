#define MAXI 1e9

class Solution {
private:
    int getMinStickers(unordered_map<string, int> &dp, vector<vector<int>> &stickerMap,
                       string &target)
    {
        if(target == "")
            return 0;
        
        if(dp.count(target))
            return dp[target];
        
        int minStickers = MAXI;
        
        for(auto sticker : stickerMap)
        {
            string remLetters = "";
            
            for(char ch : target)
            {
                if(sticker[ch - 'a'] > 0)
                    sticker[ch - 'a']--;
                
                else
                    remLetters.push_back(ch);
            }
            
            if(remLetters == target)
                continue;
            
            minStickers = min(minStickers, 1 + getMinStickers(dp, stickerMap, remLetters));
        }
        
        return dp[target] = minStickers;
    }
    
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        unordered_map<string, int> dp;
        vector<vector<int>> stickerMap(n, vector<int> (26));
        
        for(int i = 0; i < n; i++)
            for(char ch : stickers[i])
                stickerMap[i][ch - 'a']++;
        
        int answer = getMinStickers(dp, stickerMap, target);
        
        return answer == 1e9 ? -1 : answer;
    }
};