class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        string same = "";
        for(string s : words){
            mp[s]++;
            if(s[0]==s[1])
                same = s;
        }
        int ans = 0;
        if(""!=same){
            for(auto [s,f] : mp){
                if(s[0] == s[1] and s!=same and 1==mp[s]%2){
                    same = s;
                }
            }
        }
        if(""!=same){
            ans = mp[same];
            mp[same] = 0;
        }
        for(auto [s,f] : mp){
            if(0<f){
                if(s[0]==s[1]){
                    ans += (f/2)*2;
                }else{
                    string rev = s;
                    swap(rev[0],rev[1]);
                    if(0<mp[rev]){
                        ans += (min(mp[s],mp[rev])*2);
                        mp[s] = mp[rev] = 0;
                    }
                }
            }
        }
        return 2*ans;
    }
};