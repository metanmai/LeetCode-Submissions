class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        
        if(s1.length() != s2.length())
            return false;
        
        int i, j, swapped = 0;
        
        for(int k = 0; k < s1.length(); k++)
        {
            if(s1[k] != s2[k])
            {
                if(!swapped)
                    i = k;
                
                else if(swapped == 1)
                    j = k;
                
                else
                    return false;
                
                swapped++;
            }
        }
        
        if(swapped == 1)
            return false;
        
        return s1[i] == s2[j] and s2[i] == s1[j];
    }
};