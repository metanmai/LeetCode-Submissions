class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> answer;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {sum, i, j}.
        set<vector<int>> visited;
        
        pq.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});
        
        // This is kinda like dijkstra's algorithm.
        while(k-- and !pq.empty())
        {
            auto curr = pq.top(); pq.pop();
            int sum = curr[0], i = curr[1], j = curr[2];
            
            answer.push_back({nums1[i], nums2[j]});
            
            if(i < n1 - 1 and visited.find({i + 1, j}) == visited.end())
            {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }
            
            if(j < n2 - 1 and visited.find({i, j + 1}) == visited.end())
            {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        
        return answer;
    }
};