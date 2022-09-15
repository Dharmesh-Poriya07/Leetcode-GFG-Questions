class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        int len = changed.size();
        if(1==len%2)
            return ans;
        sort(changed.begin(),changed.end());
        
        map<int,int> m;
        for(int i : changed){
            m[i]++;
        }
        for(int i=0;i<len;i++){
            if(0==m[changed[i]])
                continue;
            if(0==m[2*changed[i]])
                return  {};
            ans.push_back(changed[i]);
            m[changed[i]]--;
            m[2*changed[i]]--;
            
        }
        return ans;
    }
};