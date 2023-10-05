/*
Tight tight tight.
Boyer-Moore's Voting Algorithm.
Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        int n = nums.size();
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0; // Initial value does not matter.
        
        for(int num : nums)
        {
            if(num == num1)
                cnt1++;
            
            else if(num == num2)
                cnt2++;
            
            else if(cnt1 == 0)
                num1 = num, cnt1 = 1;
            
            else if(cnt2 == 0)
                num2 = num, cnt2 = 1;
            
            else
                cnt1--, cnt2--;
        }
        
        cnt1 = cnt2 = 0;
        
        for(int num : nums)
        {
            if(num == num1)
                cnt1++;
            
            else if(num == num2)
                cnt2++;
        }
        
        if(cnt1 > n / 3)
            answer.push_back(num1);
        
        if(cnt2 > n / 3 and num1 != num2)
            answer.push_back(num2);
        
        return answer;
            
    }
};