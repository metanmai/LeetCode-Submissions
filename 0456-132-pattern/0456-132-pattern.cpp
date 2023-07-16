class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3)
            return false;
        
        stack<int> stk;
        vector<int> min_array(n);
        min_array[0] = nums[0];

        for (int i = 1; i < n; i++) 
            min_array[i] = min(min_array[i - 1], nums[i]);
        
        for (int j = n - 1; j > 0; j--) 
        {
            while (!stk.empty() and stk.top() <= min_array[j]) 
                stk.pop();
            
            if (!stk.empty() and stk.top() < nums[j])
                return true;
            
            stk.push(nums[j]);
        }
        
        return false;
    }
};