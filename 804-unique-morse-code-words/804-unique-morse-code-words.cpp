class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for(string word : words){
            string morse_code = "";
            for(char ch : word){
                for(char c : morse[ch-'a']){
                    morse_code.push_back(c);
                }
            }
            s.insert(morse_code);
        }
        return s.size();
    }
};