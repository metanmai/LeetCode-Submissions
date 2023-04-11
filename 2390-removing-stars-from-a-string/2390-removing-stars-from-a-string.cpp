class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string answer;
        
        for(char ch : s)
            if(ch != '*')
                st.push(ch);
            
            else
                st.pop();
        
        while(!st.empty())
        {
            char curr = st.top(); st.pop();
            answer.push_back(curr);
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};