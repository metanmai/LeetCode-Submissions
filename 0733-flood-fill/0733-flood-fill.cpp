// BFS Solution

class Solution {
public:
    vector<int> dirs = {0, -1, 0, 1, 0};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), initial = image[sr][sc];
        if(initial == color)
            return image;
        
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int r = front.first + dirs[i], c = front.second + dirs[i + 1];
                if(r >= 0 and c >= 0 and
                   r < m and c < n and image[r][c] == initial)
                {
                    image[r][c] = color;
                    q.push({r, c});
                }
            }
        }
        
        return image;
    }
};