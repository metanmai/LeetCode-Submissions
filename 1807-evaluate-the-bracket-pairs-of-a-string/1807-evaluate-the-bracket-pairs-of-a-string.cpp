class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length(), i = 0;
        string answer = "";
        map<string, string> known;
        
        for(auto ele : knowledge)
            known[ele[0]] = ele[1];
        
        while(i < n)
        {
            if(s[i] != '(')
            {
                answer.push_back(s[i++]);
                continue;
            }
            
            i++;
            string search = "";

            while(s[i] != ')')
                search.push_back(s[i++]);
            
            if(known.find(search) == known.end())
                answer.push_back('?');
            
            else
                answer += known[search];
            
            i++;
        }
        
        return answer;
    }
};