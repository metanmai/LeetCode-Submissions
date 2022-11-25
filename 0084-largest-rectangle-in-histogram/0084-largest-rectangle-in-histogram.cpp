class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        vector<int> prevSmall(n, -1), nextSmall(n, n);
        stack<int> st;
        
        // nextSmall calculation.
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and heights[st.top()] > heights[i])
            {
                nextSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        // prevSmall calculation.
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() and heights[st.top()] > heights[i])
            {
                prevSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i = 0; i < n; i++)
            maxArea = max(maxArea, heights[i] *(nextSmall[i] - prevSmall[i] - 1));
        
        return maxArea;
    }
};