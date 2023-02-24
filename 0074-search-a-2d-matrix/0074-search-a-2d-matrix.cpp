class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m - 1;
        
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            if(target < matrix[mid][0])
            {
                if(mid > 0)
                {
                    if(target >= matrix[mid - 1][0])
                        return binary_search(matrix[mid - 1].begin(), matrix[mid - 1].end(), target);
                    
                    high = mid - 1;
                }
                
                else
                    return false;
            }
            
            else if(target > matrix[mid][0])
                low = mid + 1;
            
            else
                return true;
        }
        
        return binary_search(matrix[high].begin(), matrix[high].end(), target);
    }
};