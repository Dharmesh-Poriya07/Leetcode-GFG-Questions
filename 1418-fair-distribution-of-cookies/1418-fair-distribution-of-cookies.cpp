class Solution {
public:
    int unfair;
    void backtrack(vector<int>& cookies,int ind,vector<int> &child){
        if(ind==cookies.size()){
            int mx = *max_element(begin(child),end(child));
            unfair = min(mx,unfair);
            return;
        }

        for(int i=0;i<child.size();i++){
            child[i] += cookies[ind];
            backtrack(cookies,ind+1,child);
            child[i] -= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        unfair = INT_MAX;
        vector<int> child(k,0);
        backtrack(cookies,0,child);
        return unfair;
    }
};