class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), minDiff = INT_MAX, minIndex;
        vector<long> leftAvg(n), rightAvg(n);
        leftAvg[0] = nums[0], rightAvg[n - 1] = nums[n - 1];
        
        for(int i = 1; i < n; i++)
        {
            leftAvg[i] = leftAvg[i - 1] + nums[i];
            rightAvg[n - 1 - i] = rightAvg[n - i] + nums[n - 1 - i];
        }
        
        for(int i = 0; i < n; i++)
            leftAvg[i] /= i + 1, rightAvg[i] /= n - i;
        
        rightAvg.push_back(0);
        
        for(int i = 0; i < n; i++)
            if(abs(leftAvg[i] - rightAvg[i + 1]) < minDiff)
            {
                minDiff = abs(leftAvg[i] - rightAvg[i + 1]);
                minIndex = i;
            }
        
        return minIndex;
    }
};