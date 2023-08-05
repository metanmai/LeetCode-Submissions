class Solution {
private:
    double findIndex(vector<int> &nums1, vector<int> &nums2, int index, int n1, int n2)
    {
        int low = 0, high = n1 - 1;
        
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            int lesser = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
            int posInArr = mid + lesser;
            
            if(posInArr == index)
                return nums1[mid];
            
            else if(posInArr < index)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        low = 0, high = n2 - 1;
        
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            int lesser = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
            int posInArr = mid + lesser;
            
            if(posInArr == index)
                return nums2[mid];
            
            else if(posInArr < index)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return -1;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), len = n1 + n2;
        double answer;
        
        if(len % 2 == 0)
        {
            double num1 = findIndex(nums1, nums2, len / 2 - 1, n1, n2);
            double num2 = findIndex(nums1, nums2, len / 2, n1, n2);
            
            return (num1 + num2) / 2.0;
        }
        
        return findIndex(nums1, nums2, len / 2, n1, n2);
    }
};