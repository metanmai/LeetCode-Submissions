class Solution {
public:
    vector<vector<int>> answer;
    
    void combinations(vector<int> candidates, vector<int> combo, int target, int start)
    {
        if(target == 0)
        {
            answer.push_back(combo);
            return;
        }
        
        if(target < 0)
            return;
        
        for(int i = start; i < candidates.size(); i++)
        {
            combo.push_back(candidates[i]);
            combinations(candidates, combo, target - candidates[i], i);
            combo.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combo;
        combinations(candidates, combo, target, 0);
        return answer;
    }
};