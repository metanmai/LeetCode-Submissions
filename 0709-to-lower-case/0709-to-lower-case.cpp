class Solution {
public:
    string toLowerCase(string s) {
        for(char &ch : s)
            if(ch - 'A' >= 0 and ch - 'A' < 26)
                ch = char(ch + 32);
        
        return s;
    }
};