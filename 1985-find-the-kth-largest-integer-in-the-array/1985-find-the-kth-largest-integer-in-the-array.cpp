template<typename T>
class myCompare
{
    public:
        bool operator() (T a, T b)
        {
            if(a.size() == b.size())
                return a > b;
            
            return a.size() > b.size();
        }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, myCompare<string>> pq;
        
        for(auto num : nums)
        {
            pq.push(num);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};