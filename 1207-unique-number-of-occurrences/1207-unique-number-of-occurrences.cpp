class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int ai : arr)
            m[ai]++;
        for(auto it : m){
            if(s.end() != s.find(it.second))
                return false;
            s.insert(it.second);
        }
        return true;
    }
};