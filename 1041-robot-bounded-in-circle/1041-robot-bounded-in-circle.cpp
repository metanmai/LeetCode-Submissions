// Check if starting point is the same as the ending point.

class Solution {
private:
    bool bounded(int x, int y, int dir, int moveCount, string instructions)
    {
        for(char ch : instructions)
        {
            if(ch == 'L')
                dir = ((dir - 1) + 4) % 4;
            
            else if(ch == 'R')
                dir = (dir + 1) % 4;
            
            else
                switch(dir)
                {
                    case 0:
                        x++; break;
                    case 1:
                        y--; break;
                    case 2:
                        x--; break;
                    case 3:
                        y++; break;
                }
        }
        
        if(x == 0 and y == 0)
            return true;
        
        if(moveCount == 4)
            return false;
        
        return bounded(x, y, dir, moveCount + 1, instructions);
    }
    
public:
    bool isRobotBounded(string instructions) {
        return bounded(0, 0, 0, 0, instructions);
    }
};