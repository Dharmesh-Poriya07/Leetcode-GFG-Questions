class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        for(int i=0;i<n;){
            int wl = words[i].size();
            int j = i+1;
            while(j<n and (wl+words[j].size()+1)<=maxWidth){
                wl += (words[j].size()+1);
                j++;
            }
            string line = "";
            if(j==n){
                line = words[i];
                for(int k=i+1;k<n;k++){
                    line.push_back(' ');
                    line += words[k];
                }
                while(line.size()<maxWidth){
                    line.push_back(' ');
                }
            }else{
                int wc = j-i;
                int actual_len = wl-wc+1;
                int spaces = wc-1;
                int spb = spaces ? (maxWidth-actual_len)/spaces : (maxWidth-actual_len);
                int rm = spaces ? (maxWidth-actual_len)%spaces : 0;
                line = words[i];
                for(int k=i+1;k<j;k++){
                    int tmp = spb;
                    while(tmp--) line.push_back(' ');
                    if(rm>0){
                        line.push_back(' ');
                        rm--;
                    }
                    line += words[k];
                }
                if(wc==1){
                    while(line.size()<maxWidth) line.push_back(' ');
                }
            }
            i = j;
            ans.push_back(line);
        }
        return ans;
    }
};