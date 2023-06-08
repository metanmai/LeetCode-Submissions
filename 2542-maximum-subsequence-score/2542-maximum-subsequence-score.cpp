class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long maxVal = 0;
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < n; i++)
            pq.push({nums2[i], nums1[i]});
        
        priority_queue<int, vector<int>, greater<>> pq2;
        long long tempSum = 0;
        
        /* At every step, we consider pq.first to be the minimum value 
        multiply that number with the max possible sum before it. */
        while(!pq.empty())
        {
            auto [val2, val1] = pq.top(); pq.pop();
            pq2.push(val1);
            tempSum += val1;
            
            // tempSum contains the max sum with k elements.
            if(pq2.size() > k)
            {
                tempSum -= pq2.top(); pq2.pop();
            }
            
            if(pq2.size() == k)
                maxVal = max(maxVal, tempSum * val2);
        }
        
        return maxVal;
    }
};