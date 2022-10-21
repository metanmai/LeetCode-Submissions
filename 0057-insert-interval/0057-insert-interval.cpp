class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size(), entered = 0, inserted = 0;
        vector<vector<int>> result;
        
        for(int i = 0; i < n; i++)
        {
            if(newInterval[1] < intervals[i][0])
            {
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin() + i, intervals.end());
                return result;
            }
            
            if(newInterval[0] > intervals[i][1])
                result.push_back(intervals[i]);
            
            else
                newInterval = {min(intervals[i][0], newInterval[0]), 
                               max(intervals[i][1], newInterval[1])};
        }
        
        result.push_back(newInterval);
        return result;
    }
};