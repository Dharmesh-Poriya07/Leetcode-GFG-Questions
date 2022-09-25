class MyCircularQueue {
public:
    int head,tail,size;
    vector<int> q;
    MyCircularQueue(int k) {
        head = tail = size = 0;
        q = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(q.size() == size) return false;
        if(0==size){
            head = tail;
        }else{
            tail ++;
            tail %= q.size();
        }
        q[tail] = value;
        size ++;
        return true;
    }
    
    bool deQueue() {
        if(0==size) return false;
        head ++;
        head %= q.size();
        size --;
        return true;
    }
    
    int Front() {
        if(0==size) return -1;
        return q[head];
    }
    
    int Rear() {
        if(0==size) return -1;
        return q[tail];
    }
    
    bool isEmpty() {
        return 0==size;
    }
    
    bool isFull() {
        return q.size()==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */