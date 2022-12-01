class Solution {
private:
    int vowels(string s)
    {
        int count = 0;
        for(char ch : s)
            if(ch == 'a' or ch == 'e' or ch == 'i' or
               ch == 'o' or ch == 'u')
                count++;
        
        return count;
    }
    
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s1 = s.substr(0, s.length() / 2), s2 = s.substr(s.length() / 2, s.length() / 2);
        
        return vowels(s1) == vowels(s2);
    }
};