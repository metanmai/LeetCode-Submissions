class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> answer(n), temp = {obstacles[0]};
        answer[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            int pos = upper_bound(temp.begin(), temp.end(), obstacles[i]) - temp.begin();
            
            if(pos == temp.size())
                temp.push_back(obstacles[i]);
            
            else
                temp[pos] = obstacles[i];
            
            answer[i] = pos + 1;
        }
        
        return answer;
    }
};