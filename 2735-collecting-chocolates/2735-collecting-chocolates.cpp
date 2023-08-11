#define ll long long

class Solution {
public:
    ll minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll> res(n);
        
        for (int i = 0; i < n; i++)
        {
            res[i] += (ll) i * x;
            int cur = nums[i];
            
            for (int k = 0; k < n; k++)
            {
                cur = min(cur, nums[(i - k + n) % n]);
                res[k] += cur;
            }
        }
        
        return *min_element(res.begin(), res.end());
    }
};