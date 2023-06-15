class Solution {
    int mod = 1000000;
    int prime = 31;
    int rabinKarp(string source,string pattern){
        if(""==source or ""==pattern or source.size()<pattern.size()) return -1;
        if(source==pattern) return 0;
        int n = source.size(), m = pattern.size();
        int power = 1;
        for(int i=0;i<m-1;i++){
            power *= prime;
            power %= mod;
        }

        int pattern_code = 0;
        for(int i=0;i<m;i++)
            pattern_code = (pattern_code * prime + pattern[i])%mod;
        
        int window_code = 0;
        for(int i=0;i<m-1;i++){
            window_code = (window_code*prime + source[i])%mod;
        }
        int i=0,j=m-1;
        for(;j<n;j++,i++){
            window_code = (((window_code%mod)*prime)%mod + source[j])%mod;
            if(window_code<0) window_code += mod;
            if(window_code == pattern_code and source.substr(i,j-i+1)==pattern){
                return i;
            }
            window_code -= (source[i]*power);
        }
        return -1;
    }
public:
    int repeatedStringMatch(string a, string b) {
        string source = a;
        int count = 1;
        while(source.size()<b.size()){
            source += a;
            count++;
        }
        if(-1 != rabinKarp(source,b)) return count;
        source += a;
        count++;
        if(-1 != rabinKarp(source,b)) return count;
        return -1;
    }
};