class Solution {
private:
    int n, totalSum;
    vector<vector<int>> probs;
    
public:
    Solution(vector<int>& w) {
        n = w.size();
        probs.resize(n);
        
        int start = 0;
        
        for(int i = 0; i < n; i++)
            probs[i] = {start, start += w[i]};
        
        totalSum = start;
    }
    
    int pickIndex() {
        int randomNum = rand() % totalSum;
        int low = 0, high = n - 1;
        
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            if(probs[mid][0] <= randomNum and probs[mid][1] > randomNum)
                return mid;
            
            else if(probs[mid][0] > randomNum)
                high = mid - 1;
            
            else
                low = mid + 1;
        }
        
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */