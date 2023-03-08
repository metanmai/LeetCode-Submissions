class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        set<int> uniqs = set(nums.begin(), nums.end());
        vector<int> numbers = vector(uniqs.begin(), uniqs.end()); // Eliminating duplicates.
        map<int, int> count;
        
        for(int num : nums)
            count[num]++;
        
        int prevMax = numbers[0] * count[numbers[0]], secondPrevMax = 0;
        
        for(int i = 1; i < numbers.size(); i++)
        {
            int curr = numbers[i] * count[numbers[i]];
            
            if(numbers[i - 1] == numbers[i] - 1)
            {
                int temp = prevMax;
                prevMax = max(curr + secondPrevMax, prevMax);
                secondPrevMax = temp;
            }
            
            else
            {
                secondPrevMax = prevMax;
                prevMax = curr + prevMax;
            }
        }
        
        return prevMax;
    }
};