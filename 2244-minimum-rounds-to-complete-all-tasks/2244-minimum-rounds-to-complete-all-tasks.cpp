class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        for(int t : tasks){
            freq[t]++;
        }
        int ans = 0;
        for(auto it : freq){
            if(1==it.second) return -1;
            if(2==it.second){
                ans ++;
                continue;
            }
            if(it.second%3) ans++;
            ans += (it.second/3);
        }
        return ans;
    }
};