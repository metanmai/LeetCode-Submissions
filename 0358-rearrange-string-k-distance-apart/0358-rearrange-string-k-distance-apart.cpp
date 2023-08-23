class Solution {
public:
    string rearrangeString(string s, int k) {
        string answer = "";
        map<char, int> freqs;
        priority_queue<pair<int, char>> canUse;
        priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, greater<>> cannotUse;
        
        for(char ch : s)
            freqs[ch]++;
        
        for(auto [ch, freq] : freqs)
            canUse.push({freq, ch});
        
        int currTime = 0;
        
        while(!canUse.empty() or !cannotUse.empty())
        {
            while(!cannotUse.empty() and cannotUse.top().first <= currTime)
            {
                auto [_, ele] = cannotUse.top(); cannotUse.pop();
                canUse.push(ele);
            }
            
            if(canUse.empty())
                return "";
            
            auto [freq, ch] = canUse.top(); canUse.pop();
            
            answer.push_back(ch);
            
            if(freq > 1)
                cannotUse.push({currTime + k, {freq - 1, ch}});
            
            currTime++;
        }
        
        return answer;
    }
};