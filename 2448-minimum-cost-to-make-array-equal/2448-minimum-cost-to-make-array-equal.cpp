#define ll long long

class Solution {
public:
    ll minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        ll low = *min_element(nums.begin(), nums.end());
        ll high = *max_element(nums.begin(), nums.end());
        
        auto totalCost = [&] (int val) -> ll
        {
            ll currCost = 0;
            
            for(int i = 0; i < n; i++)
                currCost += (long) abs(nums[i] - val) * cost[i];
            
            return currCost;
        };
        
        ll minCost = totalCost(low);
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            /* 
            If F(x) < F(x + 1), then  slope is positive, so minimum is to the left of F(x).
            If F(x) > F(x + 1), then  slope is negative, so minimum is to the right of F(x).
            */
            
            ll midCost = totalCost(mid);
            ll midNextCost = totalCost(mid + 1);
            
            minCost = min(minCost, min(midCost, midNextCost));
            
            if(midCost > midNextCost)
                low = mid + 1;
            
            else
                high = mid;
        }
        
        return minCost;
    }
};