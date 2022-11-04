class Solution {
public:
    bool isVowel(char c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
                c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U');
    }
    
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        
        while(i < j)
        {
            while(i < j and !isVowel(s[i]))
                i++;
            
            while(i < j and !isVowel(s[j]))
                j--;
            
            swap(s[i], s[j]);
            i++, j--;
        }
        
        return s;
    }
};