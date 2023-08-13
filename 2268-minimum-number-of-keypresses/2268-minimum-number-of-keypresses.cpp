class Solution {
public:
    int minimumKeypresses(string s) {
        int answer = 0, pos = 1, num = 1;;
        vector<int> letters(26);
        
        for(char ch : s)
            letters[ch - 'a']++;
        
        sort(letters.begin(), letters.end(), greater<> ());
        
        for(auto ele : letters)
        {
            answer += pos * ele;
            num++;
            
            if(num == 10)
                num = 1, pos++;
        }
        
        return answer;
    }
};