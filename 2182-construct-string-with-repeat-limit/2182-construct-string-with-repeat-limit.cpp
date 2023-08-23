class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string answer = "";
        priority_queue<pair<char, int>> canUse; // {ch, {freq, used}}
        map<char, int> freqs;
        
        for(char ch : s)
            freqs[ch]++;
        
        for(auto [ch, freq] : freqs)
            canUse.push({ch, freq});
        
        while(!canUse.empty()) {
            auto [ch, freq] = canUse.top(); canUse.pop();
            
            int len = min(repeatLimit, freq);
            /*
            The reason I have written len here and didn't directly write min(repeatLimit, freq) 
            inside the for loop is because if I perform freq-- inside the for loop, 
            the loop terminates early. 
            */
            
            for (int i = 0; i < len; i++)
                answer.push_back(ch);
            
            freq -= len;
            
            if(freq > 0)
            {
                if (!canUse.empty())
                {
                    auto [nextCh, nextFreq] = canUse.top(); canUse.pop();
                    answer.push_back(nextCh), nextFreq--;
                    
                    if (nextFreq > 0)
                        canUse.push({nextCh, nextFreq});
                }
                
                else
                    return answer;

            }

            if(freq > 0)
                canUse.push({ch, freq});
        }
        
        return answer;
    }
};