class Solution {
private:
    static bool mycmp(int &a,int &b){
        return a>=b;
    }
public:
    int minDeletions(string s) {
        vector<int> frequncy(27,0);
        for(char ch : s)
            frequncy[ch-'a'] ++;
        
        sort(frequncy.begin(),frequncy.end(),greater<int>());
        int min_deletions = 0;
        set<int> freq;
        for(int f : frequncy){
            int val = f;
            if(0==val) break;
            while(freq.end()!=freq.find(val)){
                val --;
            }
            min_deletions += (f-val);
            if(0!=val)
                freq.insert(val);
        }
        return min_deletions;
    }
};