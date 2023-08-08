class Solution {
private:
    int n, len;
    vector<vector<int>> validRanges;
    vector<vector<int>> mapping;
    
public:
    Solution(int n, vector<int>& blacklist) {
        this->n = n;
        this->len = 0;
        
        if(blacklist.size() == 0)
            return;
        
        sort(blacklist.begin(), blacklist.end());
        
        validRanges = {{0, blacklist[0]}};
        int blkLen = blacklist.size(), prevEnd = blacklist[0];
        
        for(int i = 1; i < blkLen; i++)
            validRanges.push_back({prevEnd + 1, prevEnd = blacklist[i]});
        
        validRanges.push_back({prevEnd + 1, n});
        this->len = n - blkLen;
        
        prevEnd = 0;
        auto tempRanges = validRanges;
        validRanges = {};
        
        for(auto ele : tempRanges)
            if(ele[0] != ele[1])
                validRanges.push_back(ele);
        
        for(auto ele : validRanges)
            mapping.push_back({prevEnd, prevEnd += ele[1] - ele[0]});
    }
    
    int pick() {
        if(this->len == 0)
            return rand() % n;
        
        int pickedNum = rand() % (this->len);
        int low = 0, high = mapping.size() - 1, idx = -1;
        
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            if(mapping[mid][0] <= pickedNum and mapping[mid][1] > pickedNum)
            {
                idx = mid;
                break;
            }
            
            else if(mapping[mid][0] > pickedNum)
                high = mid - 1;
            
            else
                low = mid + 1;
        }
        
        return validRanges[idx][0] + rand() % (validRanges[idx][1] - validRanges[idx][0]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */