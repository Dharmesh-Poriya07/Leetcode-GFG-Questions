class MedianFinder {
    priority_queue<int> left;
    priority_queue <int, vector<int>, greater<int>> right;
    int size;
public:
    MedianFinder() {
        this->size = 0;
    }
    
    void balanceHeaps(){
        if(1&this->size){
            left.push(right.top());
            right.pop();
        }else{
            if(left.top()>right.top()){
                right.push(left.top());
                left.pop();
                left.push(right.top());
                right.pop();
            }
        }
    }
    void addNum(int num) {
        right.push(num);        
        this->size++;
        balanceHeaps();
    }
    
    double findMedian() {
        if(this->size%2){
            return left.top();
        }
        return (left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */