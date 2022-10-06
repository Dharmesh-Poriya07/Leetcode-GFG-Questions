class TimeMap {
private:
    map<string,map<int,string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert(make_pair(timestamp,value));
        // cout<<m[key][timestamp+1]<<" ";
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].lower_bound(timestamp);
        if(it->first==timestamp){
            return it->second;
        }else if(it != m[key].begin()){
            it --;
            return it->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */