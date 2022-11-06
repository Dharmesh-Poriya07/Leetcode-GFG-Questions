class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (1<K) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 1; S.length()>i; i++)
            res = min(res, S.substr(i) + S.substr(0, i));
        return res;
    }
};