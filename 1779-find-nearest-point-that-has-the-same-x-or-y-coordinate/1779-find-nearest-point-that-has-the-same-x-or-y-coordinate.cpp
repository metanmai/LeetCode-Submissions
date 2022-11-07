class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDistance = 1e9, minIndex = -1;
        
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i][0] == x or points[i][1] == y)
            {
                int currDistance = 0;
                if(points[i][0] == x)
                    currDistance += abs(points[i][1] - y);
            
                if(points[i][1] == y)
                    currDistance += abs(points[i][0] - x);
                
                if(currDistance < minDistance)
                {
                    minDistance = currDistance;
                    minIndex = i;
                }
            }
        }
        
        return minIndex;
    }
};