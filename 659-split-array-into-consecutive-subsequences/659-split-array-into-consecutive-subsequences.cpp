class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freqm,hypom;
        for(int num : nums)
            freqm[num]++;
        for(int num : nums){
            if(0==freqm[num]) continue;
            if(0<hypom[num]){
                freqm[num]--;
                hypom[num]--;
                hypom[num+1]++;
            }else{
                if(0==freqm[num+1] || 0==freqm[num+2]) return false;
                
                freqm[num]--,freqm[num+1]--,freqm[num+2]--;
                hypom[num+3]++;
            }
        }
        return true;
    }
};