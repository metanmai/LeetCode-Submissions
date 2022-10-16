class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int l, r, maxArea = 0;
        stack<int> st;
        vector<int> prevSmall(n, -1), nextSmall(n, n); // This initialization is super important.
        
        // NextSmall calculation
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
        
        // PrevSmall calculation
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
            maxArea = max(maxArea, heights[i] * (nextSmall[i] - prevSmall[i] - 1));
        
        return maxArea;
    }
};