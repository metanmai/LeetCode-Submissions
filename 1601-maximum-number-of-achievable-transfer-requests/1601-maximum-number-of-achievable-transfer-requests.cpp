class Solution {
private:
    void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, 
                    int n, int index, int count, int &answer) {
        
        if (index == requests.size()) 
        {
            for (int i = 0; i < n; i++) 
                if (indegree[i]) 
                    return;
            
            answer = max(answer, count);
            return;
        }
        
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;

        maxRequest(requests, indegree, n, index + 1, count + 1, answer);

        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        
        maxRequest(requests, indegree, n, index + 1, count, answer);
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int answer = 0;
        vector<int> indegree(n, 0);
        
        maxRequest(requests, indegree, n, 0, 0, answer);
        return answer;
    }
};