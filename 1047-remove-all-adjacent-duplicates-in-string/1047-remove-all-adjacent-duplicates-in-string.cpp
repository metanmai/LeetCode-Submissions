class Solution {
public:
    string removeDuplicates(string s) {
        string answer = "";
        stack<char> st;
        
        for(char c : s)
            if(!st.empty() and st.top() == c)
                st.pop();
            
            else
                st.push(c);
        
        while(!st.empty())
        {
            answer.push_back(st.top());
            st.pop();
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
        
    }
};