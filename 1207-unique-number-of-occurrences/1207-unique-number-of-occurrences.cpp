class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int, int> freq;
        vector<bool> numberOfOccurences(n);
        
        for(int ele : arr)
            freq[ele]++;
        
        for(auto ele : freq)
            if(numberOfOccurences[ele.second])
                return false;
            else
                numberOfOccurences[ele.second] = true;
        
        return true;
    }
};