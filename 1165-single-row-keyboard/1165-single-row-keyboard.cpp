class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int charPos[26], moves = 0, currPos = 0;
        
        for(int i = 0; i < 26; i++)
            charPos[keyboard[i] - 'a'] = i;
        
        for(char ch : word)
        {
            moves += abs(currPos - charPos[ch - 'a']);
            currPos = charPos[ch - 'a'];
        }
        
        return moves;
    }
};