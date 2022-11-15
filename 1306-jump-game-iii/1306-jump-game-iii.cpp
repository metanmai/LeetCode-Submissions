class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n);
        queue<int> q;
        q.push(start);
        
        while(!q.empty())
        {
            int pos = q.front();
            q.pop();
            
            if(pos >= 0 and pos < n and not visited[pos])
            {
                if(arr[pos] == 0)
                    return true;
                
                visited[pos] = 1;
                q.push(pos - arr[pos]);
                q.push(pos + arr[pos]);
            }
        }
        
        return false;
    }
};