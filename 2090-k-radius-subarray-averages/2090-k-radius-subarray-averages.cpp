class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> answer(n, -1);
        vector<long long> prefix(1);
        
        for(int num : nums)
            prefix.push_back(prefix.back() + num);
        
        
        for(int i = k; i < n - k; i++)
            answer[i] = (prefix[i + k + 1] - prefix[i - k]) / (2 * k + 1);
        
        return answer;
    }
};