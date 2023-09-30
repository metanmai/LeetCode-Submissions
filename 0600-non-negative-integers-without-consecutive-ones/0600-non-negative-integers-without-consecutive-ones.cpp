class Solution {
private:
    int fibb[32];
    bool filled = false;
    
public:
    Solution()
    {
        if(filled)
            return;
        
        filled = true;
        
        fibb[0] = 1, fibb[1] = 2;
        
        for(int i = 2; i < 32; i++)
            fibb[i] = fibb[i - 1] + fibb[i - 2];
    }
    
    int findIntegers(int n) {
        int ans = 0, k = 30, pre_bit = 0;
        
        while(k >= 0) 
        {
            if(n & (1 << k)) 
            {
                ans += fibb[k];
                
                if(pre_bit) 
                    return ans;
                
                pre_bit = 1;
            }
            
            else
                pre_bit = 0;
            
            k--;
        }
        return ans + 1;
    }
};