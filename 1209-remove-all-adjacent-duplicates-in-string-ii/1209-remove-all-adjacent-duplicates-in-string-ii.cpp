class Solution {
public:
    string removeDuplicates(string s, int k) {
        string answer = "";
        stack<pair<char, int>> st;
        
        for(char c : s)
        {
            if(!st.empty() and st.top().first == c)
            {
                if(st.top().second == k - 1)
                    st.pop();
                
                else
                    st.top().second++;
            }
            
            else
                st.push({c, 1});
        }
        
        while(!st.empty())
        {
            while(st.top().second--)
                answer.push_back(st.top().first);
            
            st.pop();
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};