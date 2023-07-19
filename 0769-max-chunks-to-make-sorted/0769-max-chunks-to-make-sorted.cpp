class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), chunks = 0, maxPos = -1;
        
        for(int i = 0; i < n; i++)
        {
            maxPos = max(maxPos, max(arr[i], i));
            
            if(i == maxPos)
            {
                chunks++;
                maxPos = 0;
            }
        }
        
        return chunks;
    }
};