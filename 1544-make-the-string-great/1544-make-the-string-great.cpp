// Stack O(n) Solution.

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string answer = "";
        
        for(int i = 0; i < s.length(); i++)
            if(!st.empty() and abs(st.top() - s[i]) == 32)
                st.pop();
            
            else
                st.push(s[i]);
        
        while(!st.empty())
        {
            answer.push_back(st.top());
            st.pop();
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
        
    }
};