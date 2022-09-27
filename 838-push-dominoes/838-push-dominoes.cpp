class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        string str="";
        int i=0,j=n-1;
        vector<int> l(n,0);  
        vector<int> r(n,0);
        int prev=0,cnt=0;
        while(i<n)
        {
            if(dominoes[prev]=='R' && dominoes[i]=='.'){
                cnt++;
            }
            else {
                prev=i;
                cnt=0;
            }
            r[i]=cnt;
            i++;
        }
      
        cnt =0;
        prev=j;
        while(j>=0)
        {
            if(dominoes[prev]=='L' && dominoes[j]=='.'){
                cnt++;
            }
            else {
                prev=j;
                cnt=0;
            }
            l[j]=cnt;
            j--;
        }
           
        for(int i=0;i<n;i++)
        {
            if(l[i] < r[i] && dominoes[i]=='.' && l[i]!=0){  
                dominoes[i]='L';
            }
            if(l[i] > r[i] && dominoes[i]=='.' && r[i]==0){
                dominoes[i]='L';
            }
            if(l[i] > r[i] && dominoes[i]=='.' && r[i]!=0){
                dominoes[i]='R';
            }
            if(l[i] < r[i] && dominoes[i]=='.' && l[i]==0){
                dominoes[i]='R';
            }
            if(l[i] == r[i] && dominoes[i]=='.'){
                dominoes[i]='.';
            }
           
        }
        return dominoes;
    }
};