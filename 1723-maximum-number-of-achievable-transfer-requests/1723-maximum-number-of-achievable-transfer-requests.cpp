class Solution {
public:
    bool isValid(vector<int> &build){
        for(auto b : build)
            if(b!=0) return false;
        return true;
    }
    int backtrack(int ind,int req,vector<vector<int>>& requests,vector<int> &build){
        if(ind==requests.size()){
            return isValid(build)?req:0;
        }
        build[requests[ind][0]] --;
        build[requests[ind][1]] ++;
        int taken = backtrack(ind+1,req+1,requests,build);
        build[requests[ind][0]] ++;
        build[requests[ind][1]] --;

        int nottaken = backtrack(ind+1,req,requests,build);
        return max(taken,nottaken);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> building(n,0);
        return backtrack(0,0,requests,building);
    }
};