class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), minIndex = 0;
        vector<int> cumGas(n);
        cumGas[0] = gas[0] - cost[0];

        for(int i = 1; i < n; i++)
            cumGas[i] = cumGas[i - 1] + gas[i] - cost[i];
        
        if(cumGas.back() < 0) return -1;
        
        for(int i = 1; i < n; i++)
            if(cumGas[i] <= cumGas[minIndex])
                minIndex = i;

        return minIndex == n - 1 ? 0 : minIndex + 1;
    }
};