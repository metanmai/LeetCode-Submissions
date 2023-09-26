class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n = s.size();
        vector<int> lastPos(26, -1);
        vector<bool> inStack(26);
        string st = "";
        
        for(int i = 0; i < n; i++)
            lastPos[s[i] - 'a'] = i; 
        
        for(int i = 0; i < n; i++)
        {
            while(st.length() and st.back() > s[i] and 
                  lastPos[st.back() - 'a'] > i and !inStack[s[i] - 'a'])
            {
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            
            if(!inStack[s[i] - 'a']) 
                st.push_back(s[i]), inStack[s[i] - 'a'] = true;
        }
        
        return st;
    }
};
