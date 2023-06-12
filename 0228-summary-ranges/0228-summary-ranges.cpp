class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        nums.push_back(INT_MIN);
        long long start = nums[0], diff = 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != start + diff)
            {
                if(diff == 1)
                    answer.push_back(to_string(start));
                
                else
                    answer.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                
                start = nums[i];
                diff = 0;
            }
            
            diff++;
        }
        
        return answer;
    }
};