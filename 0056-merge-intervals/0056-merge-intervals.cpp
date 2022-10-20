class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        
        for(int i = 0; i < n - 1; i++)
        {
            if(intervals[i][1] >= intervals[i + 1][0]) // merge
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            
            else
                answer.push_back(intervals[i]);
        }
        
        answer.push_back(intervals.back());
        return answer;
    }
};