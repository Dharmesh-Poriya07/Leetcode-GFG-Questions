class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.size())) 
            return 0;
        
        int len = str.length();
        for (int i = index; i < arr.size(); i++)
            len = max(len, maxLength(arr, str+arr[i], i+1));

        return len;
    }
};