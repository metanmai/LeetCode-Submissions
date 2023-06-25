class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int low = 0, high = heights.size() - 1;
        
        auto canReach = [&] (int building) -> bool
        {
            vector<int> temp;
            
            for(int i = 1; i <= building; i++)
                temp.push_back(heights[i] - heights[i - 1]);
            
            sort(temp.begin(), temp.end());
            
            int tempBricks = bricks, tempLadders = ladders;
            int pos = 0;
            
            while(pos != building and tempBricks - temp[pos] >= 0)
            {
                if(temp[pos] > 0)
                    tempBricks -= temp[pos];
                
                pos++;
            }
            
            while(pos != building and tempLadders > 0)
            {
                if(temp[pos] > 0)
                    tempLadders--;
                
                pos++;
            }
            
            return pos == building;
        };
        
        
        while(low < high)
        {
            int mid = (high + low + 1) / 2;
            
            if(canReach(mid))
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
};