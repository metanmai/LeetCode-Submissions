/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0, high = 1e4;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(reader.get(mid) == target)
                return mid;
            
            if(reader.get(mid) > target)
                high = mid - 1;
            
            else
                low = mid + 1;
        }
        
        return -1;
    }
};