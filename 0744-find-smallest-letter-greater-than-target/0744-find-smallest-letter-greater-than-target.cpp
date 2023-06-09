class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target)
            return letters[0];

        int low = 0, high = letters.size() - 2, mid;

        while(low <= high)
        {
            mid = (low + high) / 2;
            
            if(letters[mid] == target and letters[mid + 1] > target)
                return letters[mid + 1];

            if(letters[mid] <= target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return letters[low];
    }
};