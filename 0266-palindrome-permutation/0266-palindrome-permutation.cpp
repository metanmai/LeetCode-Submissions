class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> mp;
        int mid = 0;
        
        for(char c : s)
            mp[c]++;

        for(auto ele : mp)
        {
            if(ele.second % 2 and mid)
                return false;
            
            else if(ele.second % 2 and !mid)
                mid = 1;
        }
        
        return true;
    }
};