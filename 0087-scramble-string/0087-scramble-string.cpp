class Solution {
public:
    unordered_map<string, bool> mp;
    
    bool solve(string a, string b)
    {
        if(a.compare(b) == 0) return true;
        
        if(a.length() <= 1) return false;  //1character can't be compared
        
        int n = a.length();
        bool check = false;
        
        string key = a;
        
        key += '#' + b;
        
        if(mp.find(key) != mp.end()) 
            return mp[key];
        
        for(int i = 1; i < n; i++)
        {
           bool unswap = solve(a.substr(0,i), b.substr(0,i)) and solve(a.substr(i,n - i), b.substr(i,n - i));
           bool swap = solve(a.substr(0,i), b.substr(n - i,i)) and solve(a.substr(i), b.substr(0, n - i));
            
           if(swap or unswap){
               check = true;
               break;
           }
        }
        
        return mp[key] =  check;
    }
    
    bool isScramble(string s1, string s2) 
    {
        if(s1 == s2) return true;
        
        if(s1.length() != s2.length()) return false;
        
        if(s1.empty() and s2.empty()) return true;
        
        return solve(s1,s2);
    }
};