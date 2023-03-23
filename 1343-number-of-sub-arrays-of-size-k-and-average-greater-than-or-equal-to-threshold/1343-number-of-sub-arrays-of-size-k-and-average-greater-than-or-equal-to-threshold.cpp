class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int currSum = accumulate(arr.begin(), arr.begin() + k, 0), answer = 0;
        
        for(int i = 0, j = k - 1; j < arr.size(); i++, j++)
        {
            if(i > 0)
                currSum += arr[j] - arr[i - 1];
            
            if((float) currSum / k >= threshold)
                answer++;
        }
        
        return answer;
    }
};