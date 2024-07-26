class MyQueue {
    stack<int>s1,s2;
public:
    MyQueue() {
        // stack<int> s1,s2;
    }
    void translateStacks(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
            translateStacks();
        if(s2.empty()){
            return -1;
        }
        else{
            int val = s2.top();
            s2.pop();
            return val;
        }
    }
    
    int peek() {
        if(s2.empty())
            translateStacks();
        if(s2.empty()){
            return -1;
        }
        else{
            int val = s2.top();
            // s2.pop();
            return val;
        }
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
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