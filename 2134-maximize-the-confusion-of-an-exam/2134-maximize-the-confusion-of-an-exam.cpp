class Solution {
public:
    int solve(string &answerKey,int k, char convert){
        int n = answerKey.size();
        int mxc = 0,used=0, i=0, j=0;
        while(j<n){
            while(j<n){
                if(answerKey[j]==convert) j++;
                else if(used<k){
                    used++;
                    j++;
                }else break;
            }
            mxc = max(mxc,j-i);
            if(used==k){
                while(i<j and used>=k){
                    if(answerKey[i]==convert) i++;
                    else{
                        used--;
                        i++;
                    }
                }
            }
        }
        return mxc;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = solve(answerKey,k,'T');
        int f = solve(answerKey,k,'F');
        
        return max(t,f);
    }
};