class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size(), answer = 0;
        nums.push_back(-1);
        stack<int> st;
        
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() and nums[st.top()] > nums[i])
                answer += i - st.top(), st.pop();
            
            st.push(i);
        }
        
        return answer;
    }
};