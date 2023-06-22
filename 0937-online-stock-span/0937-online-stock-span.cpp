class StockSpanner {
private:
    int index;
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;
        while(!st.empty() and st.top().second<=price){
            st.pop();
        }
        if(st.empty()){
            st.push({index,price});
            return index+1;
        }
        int ans = index-st.top().first;
        st.push({index,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */