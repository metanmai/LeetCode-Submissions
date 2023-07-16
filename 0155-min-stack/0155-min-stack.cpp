class MinStack {
private:
    vector<pair<int, int>> st;
    
public:
    MinStack() {}
    
    void push(int val) {
        int mini = 0;
        
        if(st.size() > 0)
            mini = val <= getMin() ? st.size() : st.back().second;
        
        st.push_back({val, mini});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st[st.back().second].first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */