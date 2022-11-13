class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string answer;
        int i = 0, j = 0;
        
        while(i < s.length())
        {
            j = i;
            while(i < s.length() and s[i] != ' ')
                i++;
            
            if(s.substr(j, i - j).length())
                st.push(s.substr(j, i - j));
            
            while(i < s.length() and s[i] == ' ')
                i++;
        }
        
        while(!st.empty())
        {
            answer += st.top() + " ";
            st.pop();
        }
        
        answer.pop_back();
        return answer;
    }
        
};