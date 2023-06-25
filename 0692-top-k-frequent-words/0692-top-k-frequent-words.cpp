class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqs;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
        priority_queue<pair<int, string>> pq2;
        vector<string> answer;
        
        for(auto word : words)
            freqs[word]++;
        
        for(auto [word, freq] : freqs)
        {
            pq.push({freq, word});
            
            if(pq.size() > k)
            {
                auto [currFreq, currWord] = pq.top();
                priority_queue<pair<string, int>> temppq;
                
                while(!pq.empty() and pq.top().first == currFreq)
                {
                    temppq.push({pq.top().second, pq.top().first});
                    pq.pop();
                }
                
                temppq.pop();
                
                while(!temppq.empty())
                {
                    pq.push({temppq.top().second, temppq.top().first}); temppq.pop();
                }
            }
        }
        
        while(!pq.empty())
        {
            pq2.push(pq.top()); pq.pop();
        }
        
        while(!pq2.empty())
        {
            auto [currFreq, currWord] = pq2.top();
            vector<string> strs;
            
            while(!pq2.empty() and pq2.top().first == currFreq)
            {
                strs.push_back(pq2.top().second);
                pq2.pop();
            }
            
            sort(strs.begin(), strs.end());
            
            answer.insert(answer.end(), strs.begin(), strs.end());
        }
        
        return answer;
    }
};