class Solution {
private:
    static bool myCmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),myCmp);
        
        int ans = 0;
        int mxdefens = p.back()[1];
        for(int i=p.size()-2;0<=i;i--){
            if(p[i][1]<mxdefens){
                ans ++;
            }else{
                mxdefens = p[i][1];
            }
        }
        return ans;
    }
};