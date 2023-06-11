class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> canUse;
        pair<int, char> cannotUse = {0, ' '};
        vector<int> freq(26);
        string answer(s.length(), ' ');
        
        for(char ch : s)
            freq[ch - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(freq[i] > 0)
                canUse.push({freq[i], char(i + 'a')});
        
        for(char &ch : answer)
        {
            if(canUse.size() == 0)
                return "";
            
            auto [currFreq, currChar] = canUse.top(); canUse.pop();
            ch = currChar;
            
            if(cannotUse.first != 0)
                canUse.push(cannotUse);
            
            cannotUse = {currFreq - 1, currChar};
        }
        
        return answer;
    }
};