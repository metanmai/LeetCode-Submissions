class Solution {
private:
    bool canEat(vector<int> &piles, int h, int k)
    {
        int time = 0;
        for(int bananas : piles)
        {
            time += ceil(bananas / (1.0 * k));
            if(time > h)
                return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());

        while(lo <= hi)
        {
            int mid = (hi + lo) / 2;

            if(canEat(piles, h, mid))
                hi = mid - 1;

            else
                lo = mid + 1;
        }

        return lo;
    }
};