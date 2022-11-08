// Naive Solution.

class Solution {
public:
    string makeGood(string s) {
        int i = 0, initial;
        string answer;
        
        do
        {
            i = 0, initial = s.length();
            answer = "";
            
            while(i < s.length())
                if(i != s.length() - 1 and abs(s[i] - s[i + 1]) == 32)
                    i += 2;

                else
                    answer.push_back(s[i++]);
            
            s = answer;
        }
        while(s.length() != initial);
        
        return s;
    }
};