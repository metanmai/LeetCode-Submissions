class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size(), curr = 0, total = 0;
        sort(satisfaction.begin(), satisfaction.end());
        
        for(int i = n - 1; i >= 0; i--)
        {
            curr += satisfaction[i];
            
            if(curr < 0)
                break;
            
            total += curr;
        }
        
        return total;
    }
};