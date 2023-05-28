class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
    partial_sum(stones.begin(), stones.end(), stones.begin()); // Prefix Sum (first element is not 0).
    int res = stones.back();
        
    for (int i = stones.size() - 2; i > 0; i--)
        res = max(res, stones[i] - res);
        
    return res;
    }
};