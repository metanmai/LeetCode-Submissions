/*
Binary Search Solution
Time Complexity: O(nlog(max - min))
Space Complexity: O(log n)
*/

class Solution {
private:
    int countLessOrEqual(vector<vector<int>>& matrix, int x, int n) 
    {
        int cnt = 0, c = n - 1;
        
        for (int r = 0; r < n; r++) 
        {
            while(c >= 0 and matrix[r][c] > x) 
                c--;
            
            cnt += c + 1;
        }
        
        return cnt;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1], answer = -1;
        
        while (low <= high) 
        {
            int mid = midpoint(low, high);
            
            if (countLessOrEqual(matrix, mid, n) >= k) 
                answer = mid, high = mid - 1;
            
            else 
                low = mid + 1;
        }
        
        return answer;
    }
};