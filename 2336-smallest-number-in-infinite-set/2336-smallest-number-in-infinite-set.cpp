class SmallestInfiniteSet {
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> isPresent;
public:
    SmallestInfiniteSet() {
        isPresent.push_back(0);
        for(int i=1;i<=1000;i++){
            pq.push(i);
            isPresent.push_back(1);
        }
    }
    
    int popSmallest() {
        int smallest = pq.top(); pq.pop();
        isPresent[smallest]--;
        return smallest;
    }
    
    void addBack(int num) {
        if(0==isPresent[num]){
            pq.push(num);
            isPresent[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */