class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int m = queries.size(), n = s.length(), plates = 0;;
        vector<int> candles, answer(m);
        map<int, int> prefixPlates;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
                plates++;
            
            else
            {
                candles.push_back(i);
                prefixPlates[i] = plates;
            }
            
        }
        
        if(candles.size() == 0)
            return answer;

        for(int i = 0; i < m; i++)
        {
            int leftCandle = lower_bound(candles.begin(), candles.end(), queries[i][0]) - candles.begin();
            int rightCandle = upper_bound(candles.begin(), candles.end(), queries[i][1]) - candles.begin() - 1;
            
            if(leftCandle < rightCandle)
                answer[i] = prefixPlates[candles[rightCandle]] - prefixPlates[candles[leftCandle]];
        }
        
        return answer;
    }
};