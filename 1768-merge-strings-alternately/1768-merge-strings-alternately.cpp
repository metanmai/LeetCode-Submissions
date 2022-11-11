class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer = "";
        int i = 0, j = 0, n1 = word1.length(), n2 = word2.length();
        
        while(i < n1 and j < n2)
        {
            answer.push_back(word1[i++]);
            answer.push_back(word2[j++]);
        }
        
        if(i < n1)
            answer += word1.substr(i, n1 - i);
        
        if(j < n2)
            answer += word2.substr(i, n2 - j);
        
        return answer;
    }
};