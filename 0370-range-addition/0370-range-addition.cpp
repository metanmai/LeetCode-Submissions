class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > updates)
    {
        vector<int> result(length);

        for (auto update : updates)
        {
            int start = update[0], end = update[1], val = update[2];

            result[start] += val;

            if (end < length - 1)
                result[end + 1] -= val;
        }

        partial_sum(result.begin(), result.end(), result.begin());

        return result;
    }
};