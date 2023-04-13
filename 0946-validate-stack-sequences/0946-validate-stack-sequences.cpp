class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0, n = pushed.size();
        
        while(j < n)
        {
            if(i < n)
            {
                st.push(pushed[i]);
                i++;
            }
            
            if(i == n and popped[j] != st.top())
                return false;
            
            while(j < n and !st.empty() and popped[j] == st.top())
            {
                st.pop();
                j++;
            }
        }
        
        return true;
    }
};