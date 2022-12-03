class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> studentMarks;
        vector<vector<int>> averages;
        
        for(auto item : items)
            studentMarks[item[0]].push(item[1]);
        
        for(auto student : studentMarks)
        {
            int topFive = 0, avg;
            for(int i = 1; i <= 5; i++)
                topFive += student.second.top(), student.second.pop();
            
            averages.push_back({student.first, topFive / 5});
        }
        
        return averages;
    }
};