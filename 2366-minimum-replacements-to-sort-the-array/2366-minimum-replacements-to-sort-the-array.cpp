class Solution {
private:
    using lolo = long long;
    
public:
    lolo minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        lolo answer = 0;
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] <= nums[i + 1])
                continue;
            
            lolo elements = ceil((nums[i] + nums[i + 1] - 1) / nums[i + 1]);
            
            answer += elements - 1;
            nums[i] = nums[i] / elements;
        }
        
        return answer;
    }
};