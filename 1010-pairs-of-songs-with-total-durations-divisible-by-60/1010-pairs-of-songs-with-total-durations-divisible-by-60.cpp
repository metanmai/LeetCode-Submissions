// O(nlog n) Solution.

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        sort(time.begin(), time.end());
        
        int n = time.size(), count = 0;
        int maxi = *max_element(time.begin(), time.end());
        
        for(int i = 0; i < n - 1; i++)
        {
            int start = ceil(time[i] / 60.0) * 60 - time[i];
            
            for(int key = start; key <= maxi; key += 60)
                if(binary_search(time.begin() + i + 1, time.end(), key))
                    count += (upper_bound(time.begin() + i + 1, time.end(), key) -
                              lower_bound(time.begin() + i + 1, time.end(), key));
        }
        
        return count;
    }
};