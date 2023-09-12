class Solution {
public:
    int minDeletions(string s) {
        int deletions = 0;
        vector<int> freq(26);
        map<int, vector<char>> uniqueFreqs;

        for(char ch : s)
            freq[ch - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(freq[i] != 0)
                uniqueFreqs[freq[i]].push_back(char(i + 65));

        for(auto ele : uniqueFreqs)
        {
            if(ele.second.size() > 1)
            {
                while(ele.second.size() > 1)
                {
                    char curr = ele.second.back();
                    ele.second.pop_back();
                    int temp = ele.first;
                    while(temp)
                    {
                        if(uniqueFreqs[temp].size() == 0)
                        {
                            uniqueFreqs[temp].push_back(curr);
                            break;
                        }
                        
                        temp--;
                        deletions++;
                    }
                }
            }
        }

        return deletions;
    }
};