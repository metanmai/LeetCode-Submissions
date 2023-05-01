class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0, maxi = 0, mini = INT_MAX;
        for(int sal : salary)
            sum += sal, maxi = max(maxi, sal), mini = min(mini, sal);
        
        return (double) (sum - maxi - mini) / (salary.size() - 2);
    }
};