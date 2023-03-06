class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq; // {Max value for this index, index}.
        pq.push({nums[0], 0});
        
        for(int i = 1; i < n; i++)
        {
            while(pq.top().second < i - k)
                pq.pop();
            
            auto [val, index] = pq.top();
            pq.push({nums[i] + val, i});
            
            if(i == n - 1)
                return nums[i] + val;
        }
        
        return nums[0];
    }
};