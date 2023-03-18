class BrowserHistory {
    stack<string> bck,frw;
public:
    BrowserHistory(string homepage) {
        this->frw.push(homepage);
    }
    
    void visit(string url) {
        this->frw.push(url);
        this->bck = stack<std::string>();
    }
    
    string back(int steps) {
        while(1<frw.size() and 0<steps){
            bck.push(frw.top());
            frw.pop();
            steps --;
        }
        return frw.top();
    }
    
    string forward(int steps) {
        while(0<bck.size() and 0<steps){
            frw.push(bck.top());
            bck.pop();
            steps --;
        }
        return frw.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */