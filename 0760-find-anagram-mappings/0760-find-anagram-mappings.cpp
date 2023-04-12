class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> answer;
        vector<pair<int, int>> tempNums(n);
        
        for(int i = 0; i < n; i++)
            tempNums[i] = {nums2[i], i};
        
        sort(tempNums.begin(), tempNums.end());
        
        function<int(int)> findPosition = [&] (int num) -> int
        {
            int low = 0, high = n - 1;
            
            while(low < high)
            {
                int mid = (high + low) / 2;
                
                if(tempNums[mid].first == num)
                    return tempNums[mid].second;
                
                else if(tempNums[mid].first < num)
                    low = mid + 1;
                
                else
                    high = mid - 1;
            }
            
            return tempNums[low].second;
        };
        
        for(int num : nums1)
            answer.push_back(findPosition(num));
        
        return answer;
    }
};