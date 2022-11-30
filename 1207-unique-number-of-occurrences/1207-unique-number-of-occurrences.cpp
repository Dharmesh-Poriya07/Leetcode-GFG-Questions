class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> freq;
        for(int i=0;i<arr.size();){
            int cnt = 0;
            int key = arr[i];
            while(i<arr.size() and key == arr[i]){
                cnt ++;
                i++;
            }
            freq.push_back(cnt);
        }
        sort(freq.begin(),freq.end());
        for(int i=1;i<freq.size();i++){
            if(freq[i]==freq[i-1])
                return false;
        }
        return true;
    }
};