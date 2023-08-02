class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), answer = 0;
        sort(nums.begin(), nums.end());
        
        auto isValidNum = [&] (int a, int b, int c) -> bool
        {
            return a + b > c and b + c > a and c + a > b;
        };
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int low = j, high = n - 1;
                
                while(low < high)
                {
                    int mid = (high + low + 1) / 2;
                    
                    if(isValidNum(nums[i], nums[j], nums[mid]))
                        low = mid;
                    
                    else
                        high = mid - 1;
                }
                
                answer += low - j;
            }
        }
        
        return answer;
    }
};