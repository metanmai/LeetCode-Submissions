class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), maxChainLength = 0;
        int last = INT_MIN;
        
        auto mySort = [&] (vector<int> &a, vector<int> &b) -> bool
        {
            return a[1] < b[1]; // Sort based on the second value.
        };
        
        sort(pairs.begin(), pairs.end(), mySort);
        
        for(auto pair : pairs)
            if(last < pair[0])
                last = pair[1], maxChainLength++;
        
        return maxChainLength;
    }
};