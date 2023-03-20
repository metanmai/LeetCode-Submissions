#define ff first
#define ss second

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string answer = "";
        priority_queue<pair<int, char>> pq;
        
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        
        while(!pq.empty())
        {
            auto [freq, ch] = pq.top(); pq.pop();
            
            if(freq == 0)
                continue;
            
            int n = answer.length();
            
            if(n >= 2 and 
               answer[n - 1] == ch and
               answer[n - 2] == ch)
            {
                if(pq.empty())
                    break;
                
                auto [freq2, ch2] = pq.top(); pq.pop();
                
                if(freq2 == 0)
                    continue;
                
                answer.push_back(ch2);
                freq2--;
                
                pq.push({freq2, ch2});
            }
            
            else
            {
                answer.push_back(ch);
                freq--;
            }
            
            pq.push({freq, ch});
        }
        
        return answer;
    }
};