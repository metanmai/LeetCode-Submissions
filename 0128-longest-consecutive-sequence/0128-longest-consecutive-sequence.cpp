class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxStreak = 0;
        unordered_set<int> allNums(nums.begin(), nums.end());
        
        for(int num : nums)
        {
            if(allNums.count(num - 1))
                continue;
            
            // Only the start of a sequence gets to this part, because if num - 1 is not present in the set then it must be the start of a sequence.
            int currNum = num, currStreak = 1;

            while(allNums.count(currNum + 1))
                currNum++, currStreak++;

            maxStreak = max(maxStreak, currStreak);
        }
        
        return maxStreak;
    }
};