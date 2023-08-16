class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxStreak = 0;
        unordered_set<int> allNums(nums.begin(), nums.end());
        
        for(int num : nums)
        {
            if(allNums.count(num - 1))
                continue;
            
            int currNum = num, currStreak = 1;

            while(allNums.count(currNum + 1))
                currNum++, currStreak++;

            maxStreak = max(maxStreak, currStreak);
        }
        
        return maxStreak;
    }
};