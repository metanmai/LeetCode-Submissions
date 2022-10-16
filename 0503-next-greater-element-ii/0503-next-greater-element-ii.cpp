class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        int n = nums.size(); // 2n
        stack<pair<int, int>> st;
        vector<int> answer(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and st.top().first < nums[i])
            {
                if(answer[st.top().second] == -1)
                    answer[st.top().second] = nums[i];
                
                st.pop();
            }
            st.push({nums[i], i});
        }
        
        answer.erase(answer.begin() + n / 2, answer.end());
        return answer;
    }
};