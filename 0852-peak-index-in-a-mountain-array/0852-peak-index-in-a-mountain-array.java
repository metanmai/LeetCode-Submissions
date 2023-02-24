class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 0, high = arr.length - 1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(mid < arr.length - 1 && arr[mid + 1] > arr[mid])
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
}