class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq; // We keep track of only the ending times.
    
        pq.push(intervals[0][1]);
        
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] >= pq.top())
                pq.pop();
            
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};