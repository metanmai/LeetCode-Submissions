/*
Find the number of ones in the array. This is the size of the window.
Perform sliding window from left to right of this size and find the window with the least 0s.
*/
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size(), ones = 0;
        
        for(int num : data)
            ones += num;
        
        int currOnes = 0, currZeros, minZeros;
        
        for(int j = 0; j < ones; j++)
            currOnes += data[j];
        
        currZeros = minZeros = ones - currOnes;
        currOnes -= data[0] == 1, currZeros -= data[0] == 0;
        
        for(int i = 1, j = ones; j < n; i++, j++)
        {
            if(data[j] == 1)
                currOnes++;
            
            else
                currZeros++;
            
            minZeros = min(minZeros, currZeros);
            currOnes -= data[i] == 1, currZeros -= data[i] == 0;
        }
        
        return minZeros;
    }
};