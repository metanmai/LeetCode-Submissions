class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size(), last = -1;
        vector<int> answer(n);
        unordered_map<int, int> mp;
        
        for(int num : barcodes)
            mp[num]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto ele : mp)
            pq.push({ele.second, ele.first});
        
        for(int i = 0; i < n; i++)
        {
            pair<int, int> temp = {-1, -1};
            
            if(pq.top().second == last)
            {
                temp = pq.top(); pq.pop();
            }
            
            auto [freq, num] = pq.top(); pq.pop();
            answer[i] = last = num;
            
            if(freq - 1 > 0)
                pq.push({freq - 1, num});
            
            if(temp.first != -1)
                pq.push(temp);
            
        }
        
        return answer;
    }
};