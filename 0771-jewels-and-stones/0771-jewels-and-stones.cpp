class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int answer = 0;
        set<char> myJewels;
        
        for(char ch : jewels)
            myJewels.insert(ch);
        
        for(auto jewel : stones)
            answer += myJewels.count(jewel);
        
        return answer;
    }
};