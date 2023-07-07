class Solution {
public:
    int solve(string &answerKey,int k, char convert){
        int n = answerKey.size();
        int mxc = 0,flips=0, i=0, j=0;
        while(j<n){
            if(answerKey[j]==convert) flips++;
            while(i<j and flips>k){
                flips = answerKey[i]==convert ? flips-1 : flips;
                i++;
            }
            j++;
            mxc = max(mxc,j-i);
        }
        return mxc;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = solve(answerKey,k,'F'); // converting F in to T
        int f = solve(answerKey,k,'T'); // converting T in to F
        
        return max(t,f);
    }
};