// Go read Approach 4 in leetcode's official solution. It's pretty good.

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3)
            return false;
        
        stack<int> st; // This is for the '3' in 1, 3, 2.
        vector<int> prefixMin(n); // This is for the '1' in 1, 3, 2.
        prefixMin[0] = nums[0];

        for(int i = 1; i < n; i++) 
            prefixMin[i] = min(prefixMin[i - 1], nums[i]);
        
        for(int j = n - 1; j > 0; j--) // This is for the '2' in 1, 3, 2.
        {
            while(!st.empty() and st.top() <= prefixMin[j]) 
                st.pop();
            
            if(!st.empty() and st.top() < nums[j])
                return true;
            
            st.push(nums[j]);
        }
        
        return false;
    }
};