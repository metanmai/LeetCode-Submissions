class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        
        for(int spell : spells)
        {
            int low = 0, high = potions.size();
            
            while(low < high)
            {
                int mid = (high + low) / 2;
                
                if((long long) potions[mid] * spell >= success)
                    high = mid;
                
                else
                    low = mid + 1;
            }
            
            pairs.push_back(potions.size() - low);
        }      
        
        return pairs;
    }
};