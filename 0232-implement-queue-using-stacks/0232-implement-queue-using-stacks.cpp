class MyQueue {
private:
    stack<int> output,input;
    void pushInOutput(){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            pushInOutput();
        }
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.empty()){
            pushInOutput();
        }
        return output.top();
    }
    
    bool empty() {
        if(output.empty()){
            pushInOutput();
        }
        return output.empty();
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