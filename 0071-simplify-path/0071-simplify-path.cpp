class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string answer = "/", temp = "";
        path.push_back('/');
        int len = path.length();
        
        for(int i = 0; i < len; i++)
        {
            if(path[i] != '/')
                temp.push_back(path[i]);
            
            else
            {
                if(temp == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                
                else if(temp != "." and temp != "")
                    st.push(temp);
                    
                temp = "";
            }
        }
        
        vector<string> dirs;
        while(!st.empty())
        {
            string curr = st.top(); st.pop();
            dirs.push_back(curr);
        }
        
        for(int i = dirs.size() - 1; i >= 0; i--)
            answer += dirs[i] + "/";
        
        if(answer.size() > 1)
            answer.pop_back();
        
        return answer;
    }
};