class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0, currAltitude = 0;
        
        for(int num : gain)
            maxAltitude = max(maxAltitude, currAltitude += num);
        
        return maxAltitude;
    }
};