class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int cnt = 0;
            int curr = i;
            while(curr){
                if(curr&1) cnt++;
                curr >>= 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};