class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '#';
        int low = 0, high = letters.size()-1;
        while(low<=high){
            int mid = (low+high) >> 1;
            if(letters[mid] > target){
                ans = letters[mid];
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(ans == '#') return letters.front();
        return ans;
    }
};