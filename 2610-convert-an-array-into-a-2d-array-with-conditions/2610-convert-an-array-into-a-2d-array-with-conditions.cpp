class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size(), inserted = 0;
        vector<vector<int>> answer;
        map<int, int> freqs;
        
        for(int num : nums)
            freqs[num]++;
        
        
        while(inserted < n)
        {
            vector<int> row;
            
            for(auto &[ele, freq] : freqs)
                if(freq > 0)
                {
                    row.push_back(ele);
                    freq--, inserted++;
                }
            
            answer.push_back(row);
        }
        
        return answer;
    }
};