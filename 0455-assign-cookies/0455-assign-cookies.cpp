class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0, k = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for(int i = 0; i < g.size(); i++)
        {   
            while(k < s.size() and g[i] > s[k])
                k++;
            
            if(k == s.size())
                return count;
            
            if(g[i] <= s[k++])
                count++;
        }
        
        return count;
    }
};