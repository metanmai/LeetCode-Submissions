class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        vector<int> answer(k);
        
        for(int num : arr)
        {
            pq.push({abs(num - x), num});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        for(int i = 0; i < k; i++)
        {
            answer[i] = pq.top().second; pq.pop();
        }
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};