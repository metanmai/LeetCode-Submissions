class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size(), answer = 0;
        priority_queue<int> left, right;
        vector<bool> leftValid(n);
        
        for(int i = 0; i < k; i++) 
            left.push(nums[i]), right.push(nums[n-1-i]);
        
        for (int i = k; i < n - k; i++) 
        {
            if (nums[i] > left.top()) 
                leftValid[i] = true;
            
            else 
            {
                left.pop();
                left.push(nums[i]);
            }
        }
        
        for (int i = n - k - 1; i >= k; i--) 
        {
            if (nums[i] > right.top() and leftValid[i]) 
                answer++;
            
            else 
            {
                right.pop();
                right.push(nums[i]);
            }
        }
        return answer;
    }
};