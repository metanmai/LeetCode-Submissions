// Priority queue has to maintain n / 2 elements.

class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num), right.push(left.top());
        left.pop();
        
        if(right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return left.top();
        
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */