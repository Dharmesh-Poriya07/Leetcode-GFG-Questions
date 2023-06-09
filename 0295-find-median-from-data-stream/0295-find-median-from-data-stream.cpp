class MedianFinder {
    priority_queue<int> left;
    priority_queue <int, vector<int>, greater<int>> right;
    int size;
public:
    MedianFinder() {
        this->size = 0;
    }
    
    void addNum(int num) {
        int lsz = left.size();
        int rsz = right.size();
        this->size++;
        if(lsz==rsz){
            if(lsz==0){
                left.push(num);
                return;
            }
            if(right.top()>=num){
                left.push(num);
            }else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }else{
            if(left.top()<=num){
                right.push(num);
            }else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
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