class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> answer;
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        for(int num : nums2)
        {
            while(!st.empty() and st.top() < num)
            {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        while(!st.empty())
        {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        for(auto num : nums1)
            answer.push_back(nextGreater[num]);
        
        return answer;
    }
};