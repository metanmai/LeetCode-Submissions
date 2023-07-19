class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(), k = 0;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer = {intervals[0]};
        
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] <= answer[k][1])
                answer[k][1] = max(intervals[i][1], answer[k][1]);
            
            else
            {
                answer.push_back(intervals[i]);
                k++;
            }
        }
        
        return answer;
    }
};