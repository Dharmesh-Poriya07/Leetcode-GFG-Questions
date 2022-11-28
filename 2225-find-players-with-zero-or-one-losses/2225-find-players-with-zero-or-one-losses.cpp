class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> winner,loser;
        for(auto m : matches){
            winner[m[0]]++;
            loser[m[1]]++;
        }
        for(auto w : winner)
            if(0==loser[w.first])
                ans[0].push_back(w.first);
        for(auto l : loser)
            if(1==loser[l.first])
                ans[1].push_back(l.first);
        return ans;
    }
};