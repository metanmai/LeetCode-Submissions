class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> answer(n), starts(n);
        vector<vector<int>> startIndices(n);
        
        for(int i = 0; i < n; i++)
        {
            starts[i] = intervals[i][0];
            startIndices[i] = {intervals[i][0], i};
        }
        
        sort(starts.begin(), starts.end());
        sort(startIndices.begin(), startIndices.end());
        
        for(int i = 0; i < n; i++)
        {
            int rightPos = lower_bound(starts.begin(), starts.end(), intervals[i][1]) - starts.begin();
            
            answer[i] = rightPos == n ? -1 : startIndices[rightPos][1];
        }
        
        return answer;
    }
};