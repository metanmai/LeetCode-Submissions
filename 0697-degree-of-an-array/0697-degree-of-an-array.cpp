class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, pair<int, int>> index;
        int n = nums.size(), degree = 0, minLen = n;
        
        for(int i = 0; i < n; i++)
        {
            if(freq[nums[i]] == 0)
                index[nums[i]].first = i; // Left index.

            index[nums[i]].second = i; // Right index.
            degree = max(degree, ++freq[nums[i]]);
        }
        
        for(auto ele : freq)
            if(ele.second == degree)
                minLen = min(minLen, index[ele.first].second - index[ele.first].first + 1);
        
        return minLen;
    }
};