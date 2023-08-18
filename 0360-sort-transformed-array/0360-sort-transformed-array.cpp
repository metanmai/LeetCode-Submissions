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
        int i = 0, j = n - 1, k = 0;
        
        while(i <= j)
        {
            int leftVal = getValue(nums[i], a, b, c);
            int rightVal = getValue(nums[j], a, b, c);
            
            if(a < 0)
            {
                if(leftVal < rightVal)
                    answer[k] = leftVal, i++;
            
                else
                    answer[k] = rightVal, j--;
            }
            
            else
            {
                if(leftVal > rightVal)
                    answer[k] = leftVal, i++;
            
                else
                    answer[k] = rightVal, j--;
            }
            
            k++;
        }
        
        if(a >= 0)
            reverse(answer.begin(), answer.end());
        
        return answer;
    }
};