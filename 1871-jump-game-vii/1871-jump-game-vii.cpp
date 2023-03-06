class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(0);
        
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '0')
            {
                while(!pq.empty() and i - pq.top() > maxJump)
                    pq.pop();
                
                if(!pq.empty() and i - pq.top() >= minJump)
                {
                    if(i == n - 1)
                        return true;
                    
                    pq.push(i);
                }
            }
        }
        
        return false;
    }
};