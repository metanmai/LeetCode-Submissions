class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), index = 0, i = 0;
        
        while(i < n)
        {
            int j = i;
            
            while(j < n and chars[j] == chars[i])
                j++;
            
            chars[index++] = chars[i];
            if(j - i > 1)
            {
                string len = to_string(j - i);
                
                for(char c : len)
                    chars[index++] = c;
            }
            
            i = j;
        }
        
        return index;
    }
};