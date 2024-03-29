class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0;
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            st.push(pushed[i]);
            
            while(!st.empty() and st.top() == popped[j])
                st.pop(), j++;
        }
        
        return st.empty();
    }
};