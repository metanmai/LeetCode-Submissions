// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length(), minIndex = n, minPenalty = n, leftNs = 0, leftYs = 0, totalYs = 0;
        
        for(char ch : customers)
            totalYs += ch == 'Y';
        
        for(int i = 0; i <= n; i++)
        {
            if(leftNs + totalYs - leftYs < minPenalty)
                minPenalty = leftNs + totalYs - leftYs, minIndex = i;
            
            // Idk how this is working even when i == n.
            leftYs += customers[i] == 'Y'; 
            leftNs += customers[i] == 'N';
        }
        
        return minIndex;
    }
};