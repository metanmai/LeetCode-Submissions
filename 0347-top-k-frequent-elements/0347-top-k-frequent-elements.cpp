class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        map<int, int> freqs;
        
        for(int num : nums)
            freqs[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {freq, num}
        
        for(auto [num, freq] : freqs)
        {
            pq.push({freq, num});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty())
            answer.push_back(pq.top().second), pq.pop();
        
        return answer;
    }
};