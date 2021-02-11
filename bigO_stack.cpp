class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(min.size()==0 || x<=min.top()){
            min.push(x);
            }
    }
    
    void pop() {
        if(s.size()==0)
            return;
        int ans = s.top();
        s.pop();
        if(ans == min.top())
            min.pop();
        return;
    }
    
    int top() {
        if(s.size()==0)
            return -1;
        return s.top();
    }
    
    int getMin() {
        if(min.size()==0)
            return -1;
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */