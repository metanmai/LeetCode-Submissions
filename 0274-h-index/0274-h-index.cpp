class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), maxCitations;
        sort(citations.begin(), citations.end());
        
        for(maxCitations = n; maxCitations >= 1; maxCitations--)
            if(citations[n - maxCitations] >= maxCitations)
                break;
        
        return maxCitations;
    }
};