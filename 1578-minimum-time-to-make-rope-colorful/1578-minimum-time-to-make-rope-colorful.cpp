class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mncost = 0;
        int prev = 0;
        int next = 1;
        while(colors.size()>next){
            if(colors[prev]==colors[next]){
                if(neededTime[prev] > neededTime[next]){
                    mncost += neededTime[next];
                    colors[next] = '0';
                }else{
                    mncost += neededTime[prev];
                    colors[prev] = '0';
                    prev++;
                }
                next ++;
            }else{
                prev++;
                next++;
            }
            while(colors.size()>prev and '0'==colors[prev]){
                prev++;
            }
        }
        return mncost;
    }
};