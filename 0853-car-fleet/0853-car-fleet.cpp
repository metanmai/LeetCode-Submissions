class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<int> st;
        vector<pair<int, float>> cars(n);
        
        for(int i = 0; i < n; i++)
            cars[i] = {position[i], (float) (target - position[i]) / speed[i]};
        
        sort(cars.begin(), cars.end());
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and cars[i].second >= cars[st.top()].second)
                st.pop();
            
            st.push(i);
        }
        
        return st.size();
    }
};