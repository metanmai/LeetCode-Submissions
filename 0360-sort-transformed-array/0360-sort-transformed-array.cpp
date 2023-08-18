class Solution {
private:
    int getValue(int num, int a, int b, int c)
    {
        return (a * num * num) + (b * num) + c;
    }
    
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> answer(n);
        
        for(int i = 0; i < n; i++)
            answer[i] = getValue(nums[i], a, b, c);
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};