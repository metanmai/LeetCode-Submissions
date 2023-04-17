class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> answer(n);
        
        for(int i = 0; i < n; i++)
            answer[i] = candies[i] + extraCandies >= maxCandies;
            
        return answer;
    }
};