class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left,right;
        left = right = 0;
        map<int,int> window;
        int mxans = 0;
        while(right<fruits.size()){
            window[fruits[right]]++;
            while(window.size()>2){
                window[fruits[left]]--;
                if(0==window[fruits[left]])
                    window.erase(fruits[left]);
                left++;
            }
            mxans = max(mxans,right-left+1);
            right++;
        }
        return mxans;
    }
};