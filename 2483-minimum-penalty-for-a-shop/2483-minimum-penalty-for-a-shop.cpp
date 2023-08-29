class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length(), minIndex = n, minPenalty = n, leftNs = 0;
        vector<int> rightYs(n + 1);
        
        for(int i = n - 1; i >= 0; i--)
            rightYs[i] = rightYs[i + 1] + (customers[i] == 'Y');
        
        for(int i = 0; i <= n; i++)
        {
            if(leftNs + rightYs[i] < minPenalty)
                minPenalty = leftNs + rightYs[i], minIndex = i;
            
            leftNs += customers[i] == 'N';
        }
        
        return minIndex;
    }
};