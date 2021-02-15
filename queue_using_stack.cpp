class MyQueue {
public:
    stack<int> s0;
        stack<int> s1;
        int front = -1;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s0.empty()){
            front = x;
        }
        s0.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {  
        if(s1.empty()){
            while(!s0.empty()){
            s1.push(s0.top());
            s0.pop();
        }
            int temp = s1.top();
            s1.pop();
            return temp;
        }
        
        else{
            int temp = s1.top();
            s1.pop();
            return temp;
        }
            
    
    }
    
    /** Get the front element. */
    int peek() {
        if(!s1.empty())
            return s1.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s0.empty() && s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */