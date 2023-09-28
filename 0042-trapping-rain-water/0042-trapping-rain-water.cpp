/* 
Stack Solution
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), totalWater = 0;
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while (!st.empty() and height[i] > height[st.top()]) 
            {
                int curr = st.top(); st.pop();
                
                if (st.empty())
                    break;
                
                int distance = i - st.top() - 1;
                int level = min(height[i], height[st.top()]) - height[curr];
                
                totalWater += distance * level;
            }
            
            st.push(i);
        }
        
        return totalWater;
    }
};