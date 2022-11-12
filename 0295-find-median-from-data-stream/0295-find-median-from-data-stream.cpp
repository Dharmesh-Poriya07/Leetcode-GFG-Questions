class MedianFinder {
private:
    priority_queue<int> mxHeap;
    priority_queue<int,vector<int>,greater<int>> mnHeap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int mxsz = mxHeap.size();
        int mnsz = mnHeap.size();
        
        if(0==mxsz){
            mxHeap.push(num);
        }else if(mxsz==mnsz){
            if(mnHeap.top()<num){
                int temp = mnHeap.top();
                mnHeap.pop();
                mxHeap.push(temp);
                mnHeap.push(num);
            }else{
                mxHeap.push(num);
            }
        }else if(mxsz>mnsz){
            if(mxHeap.top()>num){
                int temp = mxHeap.top();
                mxHeap.pop();
                mxHeap.push(num);
                mnHeap.push(temp);
            }else{
                mnHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        
        int sz = mnHeap.size()+mxHeap.size();
        if(0==sz%2){
            int n1 = mxHeap.top();
            int n11 = mnHeap.top();
            double ans = (n1+n11)/2.0;
            return ans;
        }
        return mxHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */