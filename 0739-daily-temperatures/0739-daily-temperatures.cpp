class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and temperatures[st.top()] < temperatures[i])
            {
                answer[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        
        return answer;
    }
};