class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();

        vector<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(st.size() > 0 and heights[st.back()] <= heights[i])
                st.pop_back();
            
            st.push_back(i);
        }
        
        return st;
    }
};