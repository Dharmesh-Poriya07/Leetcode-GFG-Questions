class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int ele : arr)
            freq[ele]++;
        
        vector<int> v;
        for(auto it : freq)
            v.push_back(it.second);
        
        sort(v.begin(),v.end(),greater<int>());
        int ans = 0,n = 0;
        while(arr.size()/2>n)
            n += v[ans++];
        
        return ans;
    }
};