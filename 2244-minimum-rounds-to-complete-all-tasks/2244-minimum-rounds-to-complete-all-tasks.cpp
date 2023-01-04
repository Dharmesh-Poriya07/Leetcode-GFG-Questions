class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        for(int t : tasks) freq[t]++;
        
        int ans = 0;
        for(auto &[key,f] : freq){
            if(1==f) return -1;
            if(2==f){
                ans ++;
                continue;
            }
            if(f%3) ans++;
            ans += (f/3);
        }
        return ans;
    }
};