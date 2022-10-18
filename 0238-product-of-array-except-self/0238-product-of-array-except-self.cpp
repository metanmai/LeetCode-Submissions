class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n, 1), rightProduct(n, 1), answer;
        
        for(int i = 1; i < n; i++)
        {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
            rightProduct[n - 1 - i] = rightProduct[n - i] * nums[n - i];
        }
        
        for(int i = 0; i < n; i++)
            answer.push_back(leftProduct[i] * rightProduct[i]);
        
        return answer;
    }
};