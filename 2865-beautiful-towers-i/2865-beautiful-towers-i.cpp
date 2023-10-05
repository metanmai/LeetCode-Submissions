/* 
Brute Force Solution.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long answer = 0;
        
        for(int i = 0; i < n; i++)
        {
            long long currVal = 0, minVal = LLONG_MAX;
            
            for(int j = i; j < n; j++)
                currVal += minVal = min(minVal, 1LL * maxHeights[j]);
            
            minVal = INT_MAX;
            
            for(int j = i; j >= 0; j--)
                currVal += minVal = min(minVal, 1LL * maxHeights[j]);
            
            answer = max(answer, currVal - maxHeights[i]);
        }
        
        return answer;
    }
};