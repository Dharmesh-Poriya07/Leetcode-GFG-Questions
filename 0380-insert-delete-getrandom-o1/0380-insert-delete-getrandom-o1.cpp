class RandomizedSet {
private:
    unordered_map<int,int> m;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(0<m[val])
            return false;
        nums.push_back(val);
        m[val] = nums.size();
        return true;
    }
    
    bool remove(int val) {
        if(0==m[val])
            return false;
        
        int index = m[val];
        nums[index-1] = nums.back();
        nums.pop_back();
        m[nums[index-1]] = index;
        m[val] = 0;
        return true;
    }
    
    int getRandom() {
        return nums[random()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */