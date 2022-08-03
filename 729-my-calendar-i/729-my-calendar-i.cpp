class MyCalendar {
    vector<pair<int,int>> temp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(temp.size()==0){
            temp.push_back({start,end});
            return true;
        }
        
        int low,high;
        low = 0,high = temp.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            auto pmid = temp[mid];
            if(pmid.second<=start){
                low = mid+1;
            }else{
                if(pmid.first<=start || pmid.first<end){
                    return false;
                }else{
                    high = mid-1;
                }
            }
        }
        temp.push_back({start,end});
        sort(temp.begin(),temp.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */