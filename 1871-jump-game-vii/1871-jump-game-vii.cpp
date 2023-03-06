// BFS Solution.

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length(), farthest = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int index = q.front(); q.pop();
            
            for(int pos = max(farthest + 1, index + minJump); pos < min(n, index + maxJump + 1); pos++)
                if(s[pos] == '0')
                {
                    if(pos == n - 1)
                        return true;
                    
                    q.push(pos);
                }
            
            farthest = index + maxJump;
        }
        
        return false;
    }
};