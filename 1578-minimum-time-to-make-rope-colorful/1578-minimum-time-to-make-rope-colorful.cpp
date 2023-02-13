class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), i = 0, minTime = 0;
        
        while(i < n)
        {
            int currSum = 0, currMax = 0, entered = 0;
            
            while(i < n - 1 and colors[i] == colors[i + 1])
            {
                entered = 1;
                currMax = max(currMax, neededTime[i]);
                currSum += neededTime[i++];
            }
            
            if(entered)
            {
                currMax = max(currMax, neededTime[i]);
                currSum += neededTime[i++];
            }
            
            minTime += currSum - currMax;
            
            if(!entered)
                i++;
        }
        
        return minTime;
    }
};