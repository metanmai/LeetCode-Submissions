class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int answer = 1, i = 0, j = 0, prev = -1;
        
        while(j < arr.size() - 1)
        {
            if(prev == -1)
            {
                if(arr[j] < arr[j + 1])
                    prev = 1;
                
                if(arr[j] > arr[j + 1])
                    prev = 0;
            }
            
            else if(prev == 1 and arr[j] > arr[j + 1])
                prev = 0;
            
            else if(prev == 0 and arr[j] < arr[j + 1])
                prev = 1;
            
            else
            {
                prev = -1;
                i = j;
                j--;
            }
            
            j++;
            if(prev != -1)
                answer = max(answer, j - i + 1);
            
            else
                i = j;
        }
        
        return answer;
    }
};