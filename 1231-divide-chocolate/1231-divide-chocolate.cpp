class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = sweetness.size(), low = 0, high = accumulate(sweetness.begin(), sweetness.end(), 0);
        int maxSweetness = 0;
        
        auto canGetSweetness = [&] (int reqSweetness) -> bool
        {
            int currSweetness = 0, cuts = 0;
            
            for(int i = 0; i < n; i++)
            {
                currSweetness += sweetness[i];
                
                if(currSweetness >= reqSweetness)
                {
                    currSweetness = 0;
                    cuts++;
                }
            }
            
            return cuts > k; // Not cuts >= k because we are counting the cut of the final piece as well.
        };
        
        while(low < high)
        {
            int mid = (low + high + 1) / 2;
            
            if(canGetSweetness(mid))
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
};