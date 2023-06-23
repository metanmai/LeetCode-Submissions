class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), low, high, row = 0, col = 0;
        vector<int> prev = {INT_MIN, INT_MIN}, curr = {-1, -1};
        
        auto checkDirs = [&] (int row, int col) -> bool
        {
            return (mat[row][col] > ((row + 1) == m ? -1 : mat[row + 1][col]) and
                    mat[row][col] > ((row - 1) == -1 ? -1 : mat[row - 1][col]) and
                    mat[row][col] > ((col + 1) == n ? -1 : mat[row][col + 1]) and
                    mat[row][col] > ((col - 1) == -1 ? -1 : mat[row][col - 1]));
        };
        
        while(!checkDirs(row, col))
        {
            // horizontal peak.
            low = 0, high = n - 1;
            
            while(low < high)
            {
                int mid = (low + high) / 2;

                if(mat[row][mid] > ((mid + 1) == n ? -1 : mat[row][mid + 1]))
                    high = mid;

                else
                    low = mid + 1;
            }
            
            col = high;
            
            if(checkDirs(row, col))
                break;

            // vertical peak.
            low = 0, high = m - 1;
            
            while(low < high)
            {
                int mid = (low + high) / 2;

                if(mat[mid][col] > ((mid + 1) == m ? -1 : mat[mid + 1][col]))
                    high = mid;

                else
                    low = mid + 1;
            }
            
            row = high;
        }
        
        return {row, col};
    }
};