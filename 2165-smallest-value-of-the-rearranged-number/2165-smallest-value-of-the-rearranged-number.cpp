#define ll long long

class Solution {
public:
    ll smallestNumber(ll num) {
        if(num == 0)
            return 0;
        
        ll answerNum = 0;
        string nums = "", answer = "";
        int neg = num < 0 ? -1 : 1;
        num *= neg;
        
        while(num > 0)
        {
            nums += to_string(num % 10);
            num /= 10;
        }
        
        int n = nums.size();
        
        if(neg == -1)
        {
            sort(nums.begin(), nums.end(), greater<> ());
            
            for(int i = n - 1; i >= 0; i--)
                answerNum += pow(10, n - 1 - i) * stoi(string(1, nums[i]));
            
            return answerNum * -1;
        }
        
        sort(nums.begin(), nums.end());
        
        int nonZeroPos = upper_bound(nums.begin(), nums.end(), '0') - nums.begin();
        answer.push_back(nums[nonZeroPos]);
        
        for(int i = 0; i < nonZeroPos; i++)
            answer.push_back('0');
        
        for(int i = nonZeroPos + 1; i < n; i++)
            answer.push_back(nums[i]);
        
        for(int i = n - 1; i >= 0; i--)
            answerNum += pow(10, n - 1 - i) * stoi(string(1, answer[i]));
        
        return answerNum;
    }
};