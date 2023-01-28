class SummaryRanges {
    set<int> nums;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int left,right;
        for(auto it = nums.begin();it!=nums.end();it++){
            right = left = *it;
            while(it!=nums.end() and right==*it){
                right++;
                it++;
            }
            it--;
            intervals.push_back({left,right-1});
        }
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */