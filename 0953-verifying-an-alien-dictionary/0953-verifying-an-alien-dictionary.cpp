class Solution {
private:
    bool isSorted(string s1,string s2,unordered_map<char,int> &pos){
        int l1 = s1.size();
        int l2 = s2.size();
        int i=0,j=0;
        while(i<l1 and j<l2 and pos[s1[i]]==pos[s2[j]]){
            i++;
            j++;
        }
        if(j==l2 and i<l1) return false;
        if(i<l1 and j<l2 and pos[s1[i]]>pos[s2[j]]) return false;
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> pos;
        for(int i=0;i<order.size();i++){
            pos[order[i]] = i+1;
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!isSorted(words[i],words[j],pos)){
                    return false;
                }
            }
        }
        return true;
    }
};