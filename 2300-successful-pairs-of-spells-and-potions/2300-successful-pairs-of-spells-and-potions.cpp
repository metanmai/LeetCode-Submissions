class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        
        function<int(int)> findSuccessPairs = [&] (int spell) -> int
        {
            int low = 0, high = m;
            
            while(low < high)
            {
                int mid = (high + low) / 2;
                
                if((long) potions[mid] * spell >= success)
                    high = mid;
                
                else
                    low = mid + 1;
            }
            
            return m - low;
        };
        
        for(int spell : spells)
            pairs.push_back(findSuccessPairs(spell));
        
        return pairs;
    }
};