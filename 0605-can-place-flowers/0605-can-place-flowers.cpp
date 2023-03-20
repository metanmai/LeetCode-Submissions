class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        
        if(flowerbed[0] == 0 and ((len > 1 and flowerbed[1] == 0) or len == 1))
        {
            flowerbed[0] = 1;
            n--;
        }
        
        for(int i = 0; i < len - 1; i++)
        {
            if(flowerbed[i] == 0 and flowerbed[i + 1] == 0 and flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        
        if(flowerbed[len - 1] == 0 and len > 1 and flowerbed[len - 2] == 0)
        {
            flowerbed[len - 1] = 1;
            n--;
        }
        
        return n <= 0;
    }
};