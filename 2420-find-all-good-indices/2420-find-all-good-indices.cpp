class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftLimit(n, 1), rightLimit(n, 1), answer;
        stack<int> st;
        
        for(int i = n - 2; i >= 0; i--)
            if(nums[i + 1] >= nums[i])
                rightLimit[i] = 1 + rightLimit[i + 1];
        
        for(int i = 1; i < n; i++)
            if(nums[i - 1] >= nums[i])
                leftLimit[i] = 1 + leftLimit[i - 1];
        
        for(int i = k; i < n - k; i++)
            if(leftLimit[i - 1] >= k and rightLimit[i + 1] >= k)
                answer.push_back(i);
        
        return answer;
    }
};