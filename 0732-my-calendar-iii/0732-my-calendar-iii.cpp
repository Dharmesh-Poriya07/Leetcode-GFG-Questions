class MyCalendarThree {
private:
    map<int,int> mp;
    int mxcount = 0;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int count = 0;
        for(auto it = mp.begin(); it!=mp.end();it ++){
            count += it->second;
            mxcount = max(mxcount,count);
        }
        return mxcount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */