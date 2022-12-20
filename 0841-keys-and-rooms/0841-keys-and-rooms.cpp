class Solution {
    int dfs(vector<vector<int>>& rooms,vector<bool> &visited,int s){
        visited[s] = true;
        int count = 1;
        for(auto key : rooms[s]){
            if(!visited[key]){
                count += dfs(rooms,visited,key);
            }
        }
        return count;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        return rooms.size()==dfs(rooms,visited,0);
    }
};