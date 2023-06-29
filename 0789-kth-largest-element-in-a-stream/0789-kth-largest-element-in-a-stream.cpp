class KthLargest {
    priority_queue<int> left;
    priority_queue <int, vector<int>, greater<int>> right;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto num : nums) left.push(num);
        while(right.size()<k and !left.empty()){
            right.push(left.top());
            left.pop();
        }
    }
    
    int add(int val) {
        left.push(val);
        if(right.size()<kth){
            right.push(left.top());
            left.pop();
        }else{
            if(right.top()<left.top()){
                right.push(left.top());
                left.pop();
                left.push(right.top());
                right.pop();
            }
        }
        return right.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */