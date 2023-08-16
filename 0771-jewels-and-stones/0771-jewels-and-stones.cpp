class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int answer = 0;
        map<char, int> myJewels, myStones;
        
        for(char ch : jewels)
            myJewels[ch]++;
        
        for(char ch : stones)
            myStones[ch]++;
        
        for(auto [jewel, _] : myJewels)
            answer += myStones[jewel];
        
        return answer;
    }
};