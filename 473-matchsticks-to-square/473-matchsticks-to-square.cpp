class Solution {
private:
    bool helper(vector<int> &m,int i,int len,vector<int> &sides){
        if(m.size()==i) return true;
        
        for(int j=0;j<4;j++){
            if(sides[j]+m[i]<=len){
                sides[j] += m[i];
                if(helper(m,i+1,len,sides))
                    return true;
                sides[j] -= m[i];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total_sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(0!=total_sum%4) return false;
        int length = total_sum/4;
        vector<int> sides(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>()); 
        return helper(matchsticks,0,length,sides);
    }
};