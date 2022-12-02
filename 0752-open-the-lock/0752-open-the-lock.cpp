class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int turns = 0;
        set<string> avoid(deadends.begin(), deadends.end());
        queue<string> q;
        q.push("0000");
        
        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                string code = q.front();
                q.pop();

                if(code == target)
                    return turns;

                if(avoid.find(code) != avoid.end())
                    continue;

                avoid.insert(code);

                for(int k = 0; k < 4; k++)
                {
                    char ch = code[k];

                    // Increment.
                    code[k] = ch == '9' ? '0' : (char) (ch + 1);
                    q.push(code);
                    code[k] = ch;

                    // Decrement.
                    code[k] = ch == '0' ? '9' : (char) (ch - 1);
                    q.push(code);
                    code[k] = ch;
                }
            }
            
            turns++;
        }
        
        return -1;
    }
};