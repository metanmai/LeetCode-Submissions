class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> myNums(n);
        string answer = "";
        for(int i = 0; i < n; i++)
            myNums[i] = to_string(nums[i]);
        
        sort(myNums.begin(), myNums.end(), 
             [&] (string &a, string &b) -> bool
            {
                return a + b < b + a;
            });
        
        for(int i = n - 1; i >= 0; i--)
            answer += myNums[i];
        
        reverse(answer.begin(), answer.end());
        
        while(answer.length() > 1 and answer.back() == '0')
            answer.pop_back();
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};