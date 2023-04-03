class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        
        int left=0, right=n-1;
        int count_ans = 0;
        while(left<=right){
            int sum = left!=right?people[left]+people[right]:people[left];
            if(sum<=limit){
                left++;
                right--;
            }else{
                right--;
            }
            count_ans ++;
        }
        return count_ans;
    }
};