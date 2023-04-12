class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int n=path.size();
        for(int i=0;i<n;i++){
            if('/'==path[i])
                continue;
            string p = "";
            while(i<n and '/'!=path[i]){
                p.push_back(path[i]);
                i++;
            }
            
            if(p.size()==2 and p[0]=='.' and p[1]=='.'){
                if(!st.empty())
                    st.pop_back();
            }else if(1<p.size() or (1==p.size() and '.'!=p[0]))
                    st.push_back(p);
            
        }
        
        string canonical = st.empty()?"/":"";
        while(!st.empty()){
            canonical.push_back('/');
            for(char p : st.front()){
                canonical.push_back(p);
            }
            st.pop_front();
        }
        return canonical;
    }
};