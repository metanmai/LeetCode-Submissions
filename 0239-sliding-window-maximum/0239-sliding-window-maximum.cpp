/*
Use a monotonic queue. The front of the queue is always going to be the largest element. 
If the front is more then k steps away from the current pointer, pop it.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> answer;
        
        for (int i = 0; i < k; i++) 
        {
            while (!dq.empty() and nums[i] >= nums[dq.back()]) 
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        answer.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++)
        {
            if(dq.front() == i - k)
                dq.pop_front();
            
            while (!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            answer.push_back(nums[dq.front()]);
        }
        
        return answer;
    }
};