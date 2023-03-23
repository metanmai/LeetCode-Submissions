class Solution {
private:
    void findMaxLength(vector<string> &arr, int pos, string str, int &maxLen)
    {
        set<char> temp = set(str.begin(), str.end());
        if(temp.size() != str.length())
            return;
        
        maxLen = fmax(maxLen, str.length());
        
        if(pos == arr.size())
            return;
        
        findMaxLength(arr, pos + 1, str + arr[pos], maxLen);
        findMaxLength(arr, pos + 1, str, maxLen);
    }
    
public:
    int maxLength(vector<string>& arr) {
        int maxLen = 0;
        
        findMaxLength(arr, 0, "", maxLen);
        return maxLen;
    }
};