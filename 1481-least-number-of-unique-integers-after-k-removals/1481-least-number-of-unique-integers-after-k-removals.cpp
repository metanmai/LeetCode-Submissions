class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> freqs;
        vector<pair<int, int>> sortedFreqs;
        int answer = 0;
        
        for(int num : arr)
            freqs[num]++;
        
        for(auto ele : freqs)
            sortedFreqs.push_back(ele);
        
        sort(sortedFreqs.begin(), sortedFreqs.end(), 
             [&] (pair<int, int> &a, pair<int, int> &b) -> bool 
             {
                 return a.second < b.second;
             });
        
        int n = sortedFreqs.size();
        
        for(int i = 0; i < n; i++)
        {
            if(sortedFreqs[i].second < k)
                k -= sortedFreqs[i].second;
            
            else if(sortedFreqs[i].second == k)
                return n - i - 1;
            
            else
                return n - i;
        }
        
        return 0;
    }
};