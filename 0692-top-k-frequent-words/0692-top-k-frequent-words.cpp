class Solution {
    static bool myCmp(pair<int,string> &a,pair<int,string> &b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first>b.first;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for(string word : words)
            freq[word]++;
        vector<pair<int,string>> v;
        for(auto it : freq)
            v.push_back({it.second,it.first});
        sort(v.begin(),v.end(),myCmp);
        vector<string> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        return ans;
    }
};