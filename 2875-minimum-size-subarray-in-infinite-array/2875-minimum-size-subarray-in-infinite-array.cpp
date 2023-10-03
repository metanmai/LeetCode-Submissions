/*
Prefix Sum Solution.
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size(), answer = 1e9;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int rounds = target / total;
        target %= total;
        
        if(target == 0)
            return rounds * n;
        
        long long currSum = 0;
        unordered_map<long long, int> prefix;
        
        for(int i = 0; i < 2 * n; i++) // Make the array circular.
        {
            currSum += (long long) nums[i % n];
            
            if(prefix.count(currSum - target))
                answer = min(answer, i - prefix[currSum - target]);
            
            prefix[currSum] = i;
        }
        
        return answer == 1e9 ? -1 : answer + rounds * n;
    }
};