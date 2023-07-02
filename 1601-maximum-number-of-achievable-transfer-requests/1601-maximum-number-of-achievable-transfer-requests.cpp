class Solution {
private:
    void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, 
                    int n, int i, int count, int &answer) {
        
        if (i == requests.size()) 
        {
            for (int i = 0; i < n; i++) 
                if (indegree[i]) 
                    return;
            
            answer = max(answer, count);
            return;
        }
        
        indegree[requests[i][0]]--;
        indegree[requests[i][1]]++;

        maxRequest(requests, indegree, n, i + 1, count + 1, answer);

        indegree[requests[i][0]]++;
        indegree[requests[i][1]]--;
        
        maxRequest(requests, indegree, n, i + 1, count, answer);
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int answer = 0;
        vector<int> indegree(n);
        
        maxRequest(requests, indegree, n, 0, 0, answer);
        return answer;
    }
};