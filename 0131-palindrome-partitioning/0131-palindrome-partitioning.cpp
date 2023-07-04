class Solution {
private:
    bool isPalindrome(string s)
    {
        string temp = s;
        reverse(begin(temp), end(temp));
        return temp == s;
    }

    void findPartitions(vector<vector<string>> &answer, vector<string> part,
                        string s, int start, int n)
    {
        if(start == n)
        {
            answer.push_back(part);
            return;
        }

        for(int i = start; i < n; i++)
        {
            string temp = s.substr(start, i - start + 1);
            
            if(isPalindrome(temp))
            {
                part.push_back(temp);
                findPartitions(answer, part, s, i + 1, n);
                part.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        
        findPartitions(answer, {}, s, 0, s.length());
        return answer;
    }
};