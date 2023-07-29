class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.back() == 0)
            return 0;
        
        int n = citations.size(), low = 1, high = n;
        
        while(low < high)
        {
            int mid = (high + low + 1) / 2;
            
            if(citations[n - mid] >= mid)
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
};