class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.length() - 1;
        string answer = "";
        
        while(i >= 0)
        {
            if(s[i] == '#')
            {
                answer.push_back(char(stoi(s.substr(i - 2, 2)) + 'a' - 1));
                i -= 3;
            }
            
            else
            {
                answer.push_back(char(stoi(s.substr(i, 1)) + 'a' - 1));
                i--;
            }
            
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};