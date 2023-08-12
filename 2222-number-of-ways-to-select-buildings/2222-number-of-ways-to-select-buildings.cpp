/* Since the sequence we are looking for is either "010" or "101",
- For "010", Check the number of 0s before and after the current 0, for every 1.
- For "101", Check the number of 1s before and after the current 0, for every 0.
*/

#define ll long long

class Solution {
public:
    ll numberOfWays(string s) {
        ll answer = 0, leftZeros = 0, rightZeros = 0, leftOnes = 0, rightOnes = 0;
        
        for(char ch : s)
        {
            if(ch == '0')
                rightZeros++;
            
            else
                rightOnes++;
        }
        
        for(char ch : s)
        {
            if(ch == '0')
            {
                answer += leftOnes * rightOnes;
                leftZeros++, rightZeros--;
            }
            
            else
            {
                answer += leftZeros * rightZeros;
                leftOnes++, rightOnes--;
            }
        }
        
        return answer;
    }
};