class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        int n = arr.size(), minDiff = 1e9;
        
        for(int i = 0; i < n - 1; i++)
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        
        for(int i = 0; i < n - 1; i++)
            if(arr[i + 1] - arr[i] == minDiff)
                answer.push_back({arr[i], arr[i + 1]});
        
        return answer;
    }
};