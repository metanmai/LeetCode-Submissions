class Solution {
private:
    bool isVowel(char ch)
    {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    
public:
    int maxVowels(string s, int k) {
        int currVowels = 0;
        
        for(int j = 0; j < k; j++)
            if(isVowel(s[j]))
                currVowels++;
        
        int maxVowels = currVowels;
        
        if(isVowel(s[0]))
            currVowels--;
        
        for(int i = 1, j = k; j < s.length(); i++, j++)
        {
            if(isVowel(s[j]))
                currVowels++;
            
            maxVowels = max(maxVowels, currVowels);
            
            if(isVowel(s[i]))
                currVowels--;
        }
        
        return maxVowels;
    }
};