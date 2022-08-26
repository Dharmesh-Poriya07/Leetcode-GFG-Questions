class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string strn = to_string(n);
        sort(strn.begin(),strn.end());
        
        vector<string> pow2;
        for(int i=0;i<31;i++){
            int p = pow(2,i);
            pow2.push_back(to_string(p));
            sort(pow2[i].begin(),pow2[i].end());
            if(pow2[i]==strn)
                return true;
        }
        return false;
    }
};