class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper_case = 0;
        for(char ch : word){
            if('A'<=ch and 'Z'>=ch) upper_case++;
        }
        if((1<upper_case and upper_case!=word.size())or(1==upper_case and 'a'<=word[0]))
            return false;
        return true;
    }
};