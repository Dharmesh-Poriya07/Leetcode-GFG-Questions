class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
	
        set<string> st{bank.begin(),bank.end()};
        
        if(!st.count(end)) return -1;
        
        queue<string> q;
        q.push(start);
        int steps=0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string current = q.front();
                q.pop();
                
                if(current==end) return steps;
                
                st.erase(current);
                
                for(int i=0;i<8;i++){
                    string temp = current;
                    temp[i]='A';
                    if(st.count(temp)) q.push(temp);
                    temp[i]='C';
                    if(st.count(temp)) q.push(temp);
                    temp[i]='G';
                    if(st.count(temp)) q.push(temp);
                    temp[i]='T';
                    if(st.count(temp)) q.push(temp);
                }
            }
            steps++;
        }
        return -1;
    }
};