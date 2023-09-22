class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n);
        
        for(auto booking : bookings)
        {
            int first = booking[0], last = booking[1], seats = booking[2];
            
            answer[first - 1] += seats;
            
            if(last != n)
                answer[last] -= seats;
        }
        
        partial_sum(answer.begin(), answer.end(), answer.begin());
        
        return answer;
    }
};