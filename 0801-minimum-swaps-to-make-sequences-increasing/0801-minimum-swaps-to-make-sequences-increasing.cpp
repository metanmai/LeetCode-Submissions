class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> swap(n), notSwap(n);
        swap[0] = 1;
        
        for (int i = 1; i < n; ++i) 
        {
            notSwap[i] = swap[i] = n;
            
            if(nums1[i - 1] < nums1[i] and nums2[i - 1] < nums2[i]) 
            {
                swap[i] = swap[i - 1] + 1;
                notSwap[i] = notSwap[i - 1];
            }
            
            if(nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i])
            {
                swap[i] = min(swap[i], notSwap[i - 1] + 1);
                notSwap[i] = min(notSwap[i], swap[i - 1]);
            }
        }
        
        return min(swap[n - 1], notSwap[n - 1]);
    }
};