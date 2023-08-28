class MyStack {
private:
    queue<int> q1;
    
public:
    MyStack() {}
    
    // O(n)
    void push(int x) {
        q1.push(x);
        int l = q1.size() - 1;
        
        while(l--)
        {
            q1.push(top());
            q1.pop();
        }
    }
    
    //O(1)
    int pop() {
        int x = top();
        q1.pop();
        
        return x;
    }
    
    //O(1)
    int top() {
        return q1.front();
    }
    
    //O(1)
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */