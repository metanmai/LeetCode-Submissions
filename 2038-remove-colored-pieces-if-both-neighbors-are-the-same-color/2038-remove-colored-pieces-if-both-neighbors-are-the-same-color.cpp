class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length() < 3)
            return false;
        
        string str;
        int a = 0, b = 0;
        for(int i = 0; i < colors.length() - 2; i++)
        {
            str = colors.substr(i, 3);
            if(str[0] == 'A' and str[1] == 'A' and str[2] == 'A')
                a++;
            
            if(str[0] == 'B' and str[1] == 'B' and str[2] == 'B')
                b++;
        }
        
        return a > b;
    }
};