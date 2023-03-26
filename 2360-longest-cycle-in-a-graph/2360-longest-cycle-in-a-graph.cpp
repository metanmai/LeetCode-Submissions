

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), answer = -1;
        vector<pair<int, int>> took(n); // To check if current edge is taken.
        for (int node = 0; node < n; ++node)
        {
            int len = 1, curr = node;
            
            while (curr != -1 and took[curr].second == 0)
            {
                took[curr] = {node, len++};
                curr = edges[curr];
            }
            
            if(curr != -1 and took[curr].first == node)
                answer = max(answer, len - took[curr].second);
        }
        return answer;
    } 
};