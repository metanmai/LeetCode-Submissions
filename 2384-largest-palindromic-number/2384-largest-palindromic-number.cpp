class Solution {
public:
    string largestPalindromic(string num) {
        map<char, int> freqs;
        string answer = "";
        char middle = ' ';
        
        for(char ch : num)
            freqs[ch]++;
        
        for(char i = '9'; i>= '0'; i--)
        {
            int freq = freqs[i];
            
            if(freq % 2 == 1 and middle == ' ')
                middle = i;
            
            freq /= 2;
            
            for(int k = 0; k < freq; k++)
                answer.push_back(i);
        }
        
        string temp = answer;
        reverse(temp.begin(), temp.end());
        
        while(temp.size() > 0 and temp.back() == '0')
            temp.pop_back();
        
        string temp2 = temp;
        
        reverse(temp.begin(), temp.end());
        
        answer = temp;
        
        if(middle != ' ')
            answer.push_back(middle);
        
        answer += temp2;
        
        return answer == "" ? "0" : answer;
    }
};