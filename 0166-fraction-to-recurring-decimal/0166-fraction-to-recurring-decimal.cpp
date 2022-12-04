class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        
        string answer = "";
        if(numerator < 0 xor denominator < 0)
            answer += "-";
        
        map<long, long> mp; // {remainder : position}.
        long num = labs(numerator), den = labs(denominator);
        long quo = num / den, rem = num % den;
        
        // Before decimal place.
        answer += to_string(quo);
        
        if(rem == 0)
            return answer;
        
        answer += ".";
        
        while(rem > 0)
        {
            if(mp.find(rem) != mp.end())
            {
                answer.insert(mp[rem], "(");
                answer += ')';
                break;
            }
            
            else
            {
                // Starting position for this particular remainder value.
                mp[rem] = answer.length();
                rem *= 10;
                quo = rem / den;
                rem = rem % den;
                answer += to_string(quo);
            }
        }
        
        return answer;
    }
};