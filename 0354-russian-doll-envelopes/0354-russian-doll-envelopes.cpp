class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        auto mySort = [&] (vector<int> &a, vector<int> &b) -> bool
        {
            if(a[0] == b[0])
                return a[1] > b[1];
            
            return a < b;
        };
        
        sort(envelopes.begin(), envelopes.end(), mySort);
        vector<int> temp;
        
        for(auto env : envelopes)
        {
            int pos = lower_bound(temp.begin(), temp.end(), env[1]) - temp.begin();
            
            if(pos == temp.size())
                temp.push_back(env[1]);
            else
                temp[pos] = env[1];
        }
        
        return temp.size();
    }
};