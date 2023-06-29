class State{
    public:
    int x,y,keys;
    State(int r,int c,int k){
        x = r;
        y = c;
        keys = k;
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        int total_keys = 0;
        int x,y; // starting positions
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if('@'==grid[i][j])
                    x=i, y=j;
                if('a'<=grid[i][j] and 'z'>=grid[i][j])
                    total_keys++;
            }
        }

        set<string> st; // visited
        st.insert(to_string(0)+" "+to_string(x)+" "+to_string(y));
        queue<State *> q;
        q.push(new State(x,y,0));
        vector<int> directions[] = {{-1,0},{0,1},{1,0},{0,-1}};
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front(); q.pop();
                if(curr->keys == (1<<total_keys)-1) return steps;
                for(auto dir : directions){
                    int nr = dir[0]+curr->x;
                    int nc = dir[1]+curr->y;
                    int keys = curr->keys;
                    if(nr>=0 and nc>=0 and nr<n and nc<m and '#'!=grid[nr][nc]){
                        char ch = grid[nr][nc];
                        if(ch>='a' and ch<='z'){
                            keys |= 1<<(ch-'a');
                        }
                        if(ch>='A' and ch<='F' and ((keys>>(ch-'A'))&1) == 0)
                            continue;
                        string str = to_string(keys)+" "+to_string(nr)+" "+to_string(nc);
                        if(st.end()==st.find(str)){
                            st.insert(str);
                            q.push(new State(nr,nc,keys));
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};