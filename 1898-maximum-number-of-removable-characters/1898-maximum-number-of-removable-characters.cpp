class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n1 = s.length(), n2 = p.length();
        int low = 0, high = removable.size();
        
        auto canRemove = [&] (set<int> &removed) -> bool
        {
            int i = 0, j = 0;
            
            while(i < n1 and j < n2)
            {
                if(s[i] == p[j] and removed.find(i) == removed.end())
                    j++;
                
                i++;
            }
            
            return j == n2;
        };
        
        while(low < high)
        {
            int mid = (high + low + 1) / 2;
            
            set<int> removed(removable.begin(), removable.begin() + mid);
            if(canRemove(removed))
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return high;
    }
};