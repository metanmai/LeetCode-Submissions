class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<int> answer;
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < m; i++)
        {
            pq.push({accumulate(mat[i].begin(), mat[i].end(), 0), i});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};