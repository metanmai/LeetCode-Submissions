class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<int, int> buckets; // {bucket number, element}.
        
        function<bool(int, int)> checkBucket = [&] (int buck, int num) -> bool
        {
            return buckets.find(buck) != buckets.end() and 
                   abs(num - buckets[buck]) <= valueDiff;
        };
        
        for(int i = 0; i < nums.size(); i++)
        {
            int currBucket = floor((float) nums[i] / ((float) valueDiff + 1));
            
            if(buckets.find(currBucket) != buckets.end())
                return true;
            
            else
            {
                buckets[currBucket] = nums[i];
                
                if(checkBucket(currBucket - 1, nums[i]) or 
                   checkBucket(currBucket + 1, nums[i]))
                    return true;
            }
            
            if(buckets.size() > indexDiff) // Only indexDiff number of buckets are required.
            {
                int wasteBucket = floor((float) nums[i - indexDiff] / ((float) valueDiff + 1));
                buckets.erase(wasteBucket);
            }
        }
        
        return false;
    }
};