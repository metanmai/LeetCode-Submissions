class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length())
            return {};
        
        vector<int> sFreq(26), pFreq(26);
        vector<int> answer;
        
        for(int i = 0; i < p.size(); i++)
        {
            sFreq[s[i] - 'a']++;
            pFreq[p[i] - 'a']++;
        }
        
        for(int i = p.size(); i < s.size() + 1; i++)
        {
            if(sFreq == pFreq)
                answer.push_back(i - p.size());
            
            if(i == s.size())
                break;
            
            sFreq[s[i - p.size()] - 'a']--;
            sFreq[s[i] - 'a']++;
        }
        
        return answer;
    }
};