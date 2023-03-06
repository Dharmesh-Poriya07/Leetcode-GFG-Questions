class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        int steps = 0;
        vector<int> vis(arr.size()+1,false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int current = q.front(); q.pop();
                    
                if(current==arr.size()-1) return steps;
                if(current>0 && !vis[current-1]){
                    q.push(current-1);
                    vis[current-1] =  true;
                }
                if(current<arr.size() && !vis[current+1]){
                    q.push(current+1);
                    vis[current+1] =  true;
                }
                for(int ind : mp[arr[current]]){
                    if(!vis[ind]){
                        q.push(ind);
                        vis[ind] =  true;
                    }
                }
                mp[arr[current]].clear();
            }
            steps++;
        }
        return steps;
    }
};