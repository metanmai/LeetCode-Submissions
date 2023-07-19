class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> answer;
        
        for(int i = 0; i < n; i++)
        {
            if(newInterval[1] < intervals[i][0])
            {
                answer.push_back(newInterval);
                answer.insert(answer.end(), intervals.begin() + i, intervals.end());
                return answer;
            }
            
            if(newInterval[0] > intervals[i][1])
                answer.push_back(intervals[i]);
            
            else
                newInterval = {min(intervals[i][0], newInterval[0]), 
                               max(intervals[i][1], newInterval[1])};
        }
        
        answer.push_back(newInterval);
        return answer;
    }
};