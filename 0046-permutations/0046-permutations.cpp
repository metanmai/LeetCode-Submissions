class Solution {
private:
    void permutations(vector<vector<int>> &answer, vector<int> nums, 
                      vector<int> perm, vector<bool> &taken, int n)
    { 
        if(perm.size() == n)
        {
            answer.push_back(perm);
            return;
        }

        for(int i = 0; i < n; i++)
            if(!taken[i])
            {
                perm.push_back(nums[i]);
                taken[i] = true;
                permutations(answer, nums, perm, taken, n);
                perm.pop_back();
                taken[i] = false;
            }
    }

public: 
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        vector<bool> taken(n);

        permutations(answer, nums, {}, taken, n);
        return answer;
    }
};