class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count = 0;
        map<string, int> mp;
        
        for(string word : words)
        {
            string temp = word;
            reverse(word.begin(), word.end());
            
            if(mp[word])
            {
                mp[word]--;
                count += 4;
            }
            
            else
                mp[temp]++;
        }
        
        for(auto ele : mp)
        {
            string word = ele.first;
            if(ele.second and word[0] == word[1])
            {
                count += 2;
                break;
            }
        }
        
        return count;
    }
};