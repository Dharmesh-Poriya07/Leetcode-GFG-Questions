class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int mxc = 0,used=0, i=0, j=0;
        while(j<n){
            while(j<n){
                if(answerKey[j]=='T') j++;
                else if(used<k){
                    used++;
                    j++;
                }else break;
            }
            mxc = max(mxc,j-i);
            if(used==k){
                while(i<j and used>=k){
                    if(answerKey[i]=='T') i++;
                    else{
                        used--;
                        i++;
                    }
                }
            }
        }
        i=j=0;
        used=0;
        while(j<n){
            while(j<n){
                if(answerKey[j]=='F') j++;
                else if(used<k){
                    used++;
                    j++;
                }else break;
            }
            mxc = max(mxc,j-i);
            if(used==k){
                while(i<j and used>=k){
                    if(answerKey[i]=='F') i++;
                    else{
                        used--;
                        i++;
                    }
                }
            }
        }
        return mxc;
    }
};