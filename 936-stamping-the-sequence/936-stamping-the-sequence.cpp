class Solution {
private:
    int check(string &str,string &stamp){
        int n = str.size();
        for(int i=0;i<n;i++){
            int j=0,temp=i;
            bool flag = false;
            while(j<stamp.size() and temp<n and ('?'==str[temp] || str[temp]==stamp[j])){
                if(str[temp]==stamp[j])
                    flag = true;
                temp++;
                j++;
            }
            if(j==stamp.size() and flag){
                for(int k=0;k<stamp.size();k++)
                    str[i+k] = '?';
                return i;
            }
        }
        
        return n;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        string str = target;
        string ff(target.size(),'?');
        while(str!=ff){
            int value = check(str,stamp);
            if(value==str.size())
                return {};
            ans.push_back(value);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};