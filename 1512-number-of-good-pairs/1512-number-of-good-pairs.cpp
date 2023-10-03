class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int answer = 0;
        map<int, int> freqs;
        
        for(int num : nums)
            freqs[num]++;
        
        for(auto [_, freq] : freqs)
            answer += freq * (freq - 1) / 2;
        
        return answer;
    }
};