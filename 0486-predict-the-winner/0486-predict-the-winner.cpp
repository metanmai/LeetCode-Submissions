class Solution {
private:
    bool canWin(vector<int> &nums, int i, int j, int score, int totalSum, bool turn)
    {
        if(i > j)
            return score >= totalSum - score;
        
        if(turn)
            return (canWin(nums, i + 1, j, score + nums[i], totalSum, false) or
                    canWin(nums, i, j - 1, score + nums[j], totalSum, false));
        
        else
            return (canWin(nums, i + 1, j, score, totalSum, true) and
                    canWin(nums, i, j - 1, score, totalSum, true));
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        return canWin(nums, 0, n - 1, 0, totalSum, true);
    }
};