class Solution {
public:
    string customSortString(string order, string s) {
        int n1 = order.length(), n2 = s.length();
        vector<int> sortPos(26);
        
        for(int i = 0; i < n1; i++)
            sortPos[order[i] - 'a'] = i;
        
        auto mySort = [&] (char &a, char &b) -> bool
        {
            return sortPos[a - 'a'] < sortPos[b - 'a'];
        };
        
        sort(s.begin(), s.end(), mySort);
        
        return s;
    }
};