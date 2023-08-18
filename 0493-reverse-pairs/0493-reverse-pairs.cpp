class Solution {
private:
    int answer = 0;
    
    template<typename T>
    void countPairs(const vector<T> &arr1, const vector<T> &arr2)
    {
        auto it2 = arr2.begin();
        
        for(auto it1 = arr1.begin(); it1 != arr1.end(); it1++)
        {
            while(it2 != arr2.end() and 1LL * (*it1) > 1LL * 2 * (*it2))
                it2++;
            
            answer += distance(arr2.begin(), it2);
        }
    }
    
    template<typename T>
    vector<T> mergeSort(const vector<T> &arr, int l, int r)
    {
        if(l < r)
        {
            int mid = (l + r) / 2;
            vector<T> leftArr = mergeSort(arr, l, mid);
            vector<T> rightArr = mergeSort(arr, mid + 1, r);
            
            countPairs(leftArr, rightArr);
            
            return mergeArrays(leftArr, rightArr);
        }
        
        return {arr[l]};
    }
    
    template<typename T>
    vector<T> mergeArrays(const vector<T> &arr1, const vector<T> &arr2)
    {
        vector<T> combined;
        auto it1 = arr1.begin(), it2 = arr2.begin();
        
        while(it1 != arr1.end() and it2 != arr2.end())
        {
            if(*it1 < *it2)
            {
                combined.push_back(*it1);
                it1++;
            }
            
            else
            {
                combined.push_back(*it2);
                it2++;
            }
        }
        
        while(it1 != arr1.end())
        {
            combined.push_back(*it1);
            it1++;
        }
        
        while(it2 != arr2.end())
        {
            combined.push_back(*it2);
            it2++;
        }
        
        return combined;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        mergeSort<int>(nums, 0, nums.size() - 1);
        
        return answer;
    }
};